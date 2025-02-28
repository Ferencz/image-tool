#include <iostream>
#include <map>
#include <napi.h>
#include <opencv2/quality.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <vector>

double calculateSSIM(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat ssim_map;
    cv::Scalar mssim = cv::quality::QualitySSIM::compute(img1, img2, ssim_map);
    return mssim[0];
}

std::string base64Decode(const std::string &in) {
    std::string out;
    std::vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;

    int val = 0, valb = -8;
    for (unsigned char c : in) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}

cv::Mat decodeBase64ToMat(const std::string& base64Str) {
    std::string decodedData = base64Decode(base64Str);
    std::vector<uchar> data(decodedData.begin(), decodedData.end());
    return cv::imdecode(data, cv::IMREAD_COLOR);
}

cv::Mat readImage(const std::string& imagePath) {
    if (imagePath.substr(0, 5) == "data:") {
        std::string base64Str = imagePath.substr(imagePath.find(",") + 1);
        return decodeBase64ToMat(base64Str);
    } else {
        return cv::imread(imagePath, cv::IMREAD_COLOR);
    }
}

bool isSupportedExtension(const std::string& extension) {
    static const std::vector<std::string> supportedExtensions = { ".jpg", ".jpeg", ".png", ".bmp", ".tiff", ".webp" };
    return std::find(supportedExtensions.begin(), supportedExtensions.end(), extension) != supportedExtensions.end();
}

cv::Mat readImageBuffer(const std::vector<uchar>& imageBuffer) {
    cv::Mat img = cv::imdecode(imageBuffer, cv::IMREAD_COLOR);
    if (img.empty()) {
        throw std::runtime_error("Failed to decode image from buffer.");
    }
    return img;
}

std::string getFileExtension(const std::string& filePath) {
    size_t dotPos = filePath.find_last_of(".");
    if (dotPos == std::string::npos) return "";
    return filePath.substr(dotPos);
}

cv::Mat resizeToMatch(const cv::Mat& image, const cv::Mat& targetImage) {
    cv::Mat resizedImage;
    if (image.size() != targetImage.size()) {
        cv::resize(image, resizedImage, targetImage.size());
    } else {
        resizedImage = image;
    }
    return resizedImage;
}

cv::Mat convertToGrayscale(const cv::Mat& img) {
    cv::Mat grayImage;
    cv::cvtColor(img, grayImage, cv::COLOR_BGR2GRAY);
    return grayImage;
}

Napi::Value resizeImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    try {
        if (info.Length() < 2) {
            Napi::TypeError::New(env, "Expected at least two arguments").ThrowAsJavaScriptException();
            return env.Null();
        }

        cv::Mat image;
        if (info[0].IsBuffer()) {
            Napi::Buffer<unsigned char> buffer = info[0].As<Napi::Buffer<unsigned char>>(); // Corrected line
            std::vector<unsigned char> imageData(buffer.Data(), buffer.Data() + buffer.Length());
            image = readImageBuffer(imageData);
        } else if (info[0].IsString()) {
            std::string path = info[0].As<Napi::String>().Utf8Value();
            image = readImage(path);
        } else {
            Napi::Error::New(env, "Input must be a string (image path) or buffer (image data)").ThrowAsJavaScriptException();
            return env.Null();
        }

        std::string outputPath = info[1].As<Napi::String>().Utf8Value();

        int zoom = 2;

        if (info.Length() > 2 && info[2].IsNumber()) {
            zoom = info[2].As<Napi::Number>().Int32Value();
        }

        if (image.empty()) {
            Napi::Error::New(env, "Could not open or find the image").ThrowAsJavaScriptException();
            return env.Null();
        }

        cv::Mat resizedImage;
        cv::resize(image, resizedImage, cv::Size(image.cols / zoom, image.rows / zoom));


        std::string extension = getFileExtension(outputPath);
        if (extension.empty() || !isSupportedExtension(extension)) {
            extension = ".png";
            outputPath += extension;
        }

        if (!isSupportedExtension(extension)) {
            Napi::Error::New(env, "Unsupported file extension: " + extension).ThrowAsJavaScriptException();
            return env.Null();
        }

        if (!cv::imwrite(outputPath, resizedImage)) {
            Napi::Error::New(env, "Could not save the resized image").ThrowAsJavaScriptException();
            return env.Null();
        }
        return Napi::Boolean::New(env, true);

    } catch (const cv::Exception& e) {
        std::cerr << "OpenCV Exception caught: " << e.what() << std::endl;
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return env.Null();
    } catch (const std::exception& e) {
        std::cerr << "Standard Exception caught: " << e.what() << std::endl;
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return env.Null();
    }
}

Napi::Value grayscaleImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    try {
        if (info.Length() < 2) {
            Napi::TypeError::New(env, "Expected two arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        cv::Mat image;
        if (info[0].IsBuffer()) {
            // Extract buffer and convert to vector
            Napi::Buffer<char> buffer = info[0].As<Napi::Buffer<char>>();
            std::vector<unsigned char> imageData(buffer.Data(), buffer.Data() + buffer.Length());
            image = readImageBuffer(imageData);  // Pass vector to readImageBuffer
        } else if (info[0].IsString()) {
            std::string path = info[0].As<Napi::String>().Utf8Value();
            image = readImage(path);  // Use readImage function for path
        } else {
            Napi::Error::New(env, "Input must be a string (image path) or buffer (image data)").ThrowAsJavaScriptException();
            return env.Null();
        }
        std::string outputPath = info[1].As<Napi::String>().Utf8Value();

        std::string extension = getFileExtension(outputPath);
        if (!isSupportedExtension(extension)) {
            Napi::Error::New(env, "Unsupported file extension: " + extension).ThrowAsJavaScriptException();
            return env.Null();
        }

        if (image.empty()) {
            Napi::Error::New(env, "Could not open or find the image").ThrowAsJavaScriptException();
            return env.Null();
        }
        cv::Mat grayImage = convertToGrayscale(image);

        if (!cv::imwrite(outputPath, grayImage)) {
            Napi::Error::New(env, "Could not save the grayscale image").ThrowAsJavaScriptException();
            return env.Null();
        }

        return Napi::Boolean::New(env, true);
    } catch (const cv::Exception& e) {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return env.Null();
    } catch (const std::exception& e) {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return env.Null();
    }
}

Napi::Value compareImages(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    try {
        if (info.Length() < 2) {
            Napi::TypeError::New(env, "Expected two arguments: image 1 and image 2").ThrowAsJavaScriptException();
            return env.Null();
        }

        cv::Mat image1;
        cv::Mat image2;

        if (info[0].IsBuffer()) {
            Napi::Buffer<unsigned char> buffer = info[0].As<Napi::Buffer<unsigned char>>(); // Corrected buffer type
            std::vector<unsigned char> imageData(buffer.Data(), buffer.Data() + buffer.Length());
            image1 = readImageBuffer(imageData);
        } else if (info[0].IsString()) {
            std::string path = info[0].As<Napi::String>().Utf8Value();
            image1 = readImage(path);
        } else {
            Napi::Error::New(env, "Input must be a string (image path) or buffer (image data)").ThrowAsJavaScriptException();
            return env.Null();
        }

        if (info[1].IsBuffer()) {
            Napi::Buffer<unsigned char> buffer = info[1].As<Napi::Buffer<unsigned char>>(); // Corrected buffer type
            std::vector<unsigned char> imageData(buffer.Data(), buffer.Data() + buffer.Length());
            image2 = readImageBuffer(imageData);
        } else if (info[1].IsString()) {
            std::string path = info[1].As<Napi::String>().Utf8Value();
            image2 = readImage(path);
        } else {
            Napi::Error::New(env, "Input must be a string (image path) or buffer (image data)").ThrowAsJavaScriptException();
            return env.Null();
        }

        if (image1.empty() || image2.empty()) {
            Napi::Error::New(env, "Could not open or find the images").ThrowAsJavaScriptException();
            return env.Null();
        }

        // Resize the larger image to the size of the smaller image
        if (image1.size().area() > image2.size().area()) {
            cv::resize(image1, image1, image2.size());
        } else if (image2.size().area() > image1.size().area()) {
            cv::resize(image2, image2, image1.size());
        }

        cv::Mat grayImage1 = convertToGrayscale(image1);
        cv::Mat grayImage2 = convertToGrayscale(image2);

        double grayscaleSSIM = calculateSSIM(grayImage1, grayImage2);

        double colorSSIM = 0.0;
        if (image1.channels() == 3 && image2.channels() == 3) {
            colorSSIM = calculateSSIM(image1, image2);
        }

        double averageSSIM = (grayscaleSSIM + colorSSIM) / 2.0;

        Napi::Object result = Napi::Object::New(env);
        result.Set("grayscaleComparison", Napi::Number::New(env, grayscaleSSIM));
        result.Set("colorComparison", Napi::Number::New(env, colorSSIM));
        result.Set("averageComparison", Napi::Number::New(env, averageSSIM));

        return result;
    } catch (const cv::Exception& e) {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return env.Null();
    } catch (const std::exception& e) {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return env.Null();
    }
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "resizeImage"), Napi::Function::New(env, resizeImage));
    exports.Set(Napi::String::New(env, "grayscaleImage"), Napi::Function::New(env, grayscaleImage));
    exports.Set(Napi::String::New(env, "compareImages"), Napi::Function::New(env, compareImages));
    return exports;
}

NODE_API_MODULE(image_api, Init)