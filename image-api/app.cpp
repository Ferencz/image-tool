#include <napi.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>
#include <string>

// Base64 decoding function
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

// Function to decode base64 to cv::Mat
cv::Mat decodeBase64ToMat(const std::string& base64Str) {
    std::string decodedData = base64Decode(base64Str);
    std::vector<uchar> data(decodedData.begin(), decodedData.end());
    return cv::imdecode(data, cv::IMREAD_COLOR);
}

// Function to read an image from a file or base64 string
cv::Mat readImage(const std::string& imagePath) {
    if (imagePath.substr(0, 5) == "data:") {
        std::string base64Str = imagePath.substr(imagePath.find(",") + 1);
        return decodeBase64ToMat(base64Str);
    } else {
        return cv::imread(imagePath, cv::IMREAD_COLOR);
    }
}

// Function to check if a file extension is supported by OpenCV
bool isSupportedExtension(const std::string& extension) {
    static const std::vector<std::string> supportedExtensions = { ".jpg", ".jpeg", ".png", ".bmp", ".tiff", ".webp" };
    return std::find(supportedExtensions.begin(), supportedExtensions.end(), extension) != supportedExtensions.end();
}

// Helper function to get the file extension
std::string getFileExtension(const std::string& filePath) {
    size_t dotPos = filePath.find_last_of(".");
    if (dotPos == std::string::npos) return "";
    return filePath.substr(dotPos);
}

// Helper function to resize the larger image to match the size of the smaller image
cv::Mat resizeToMatch(const cv::Mat& image, const cv::Mat& targetImage) {
    cv::Mat resizedImage;
    if (image.size() != targetImage.size()) {
        cv::resize(image, resizedImage, targetImage.size());
    } else {
        resizedImage = image;
    }
    return resizedImage;
}

Napi::Value resizeImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    try {
        if (info.Length() < 2) {
            Napi::TypeError::New(env, "Expected two arguments").ThrowAsJavaScriptException();
            return env.Null();
        }

        std::string inputPath = info[0].As<Napi::String>().Utf8Value();
        std::string outputPath = info[1].As<Napi::String>().Utf8Value();

        // Get the file extension for output image
        std::string extension = getFileExtension(outputPath);

        // Check if the extension is empty or not supported, use .png as a fallback
        if (extension.empty() || !isSupportedExtension(extension)) {
            extension = ".png";  // Default to .png if extension is invalid or missing
            outputPath += extension;  // Add default extension
        }

        // Validate the final extension after ensuring it's valid
        if (!isSupportedExtension(extension)) {
            Napi::Error::New(env, "Unsupported file extension: " + extension).ThrowAsJavaScriptException();
            return env.Null();
        }

        cv::Mat image = readImage(inputPath);
        if (image.empty()) {
            Napi::Error::New(env, "Could not open or find the image").ThrowAsJavaScriptException();
            return env.Null();
        }

        // Resize the image
        cv::Mat resizedImage;
        cv::resize(image, resizedImage, cv::Size(image.cols / 2, image.rows / 2));

        // Try saving the resized image
        if (!cv::imwrite(outputPath, resizedImage)) {
            Napi::Error::New(env, "Could not save the resized image").ThrowAsJavaScriptException();
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

// Function to convert image to grayscale
Napi::Value grayscaleImage(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    try {
        if (info.Length() < 2) {
            Napi::TypeError::New(env, "Expected two arguments").ThrowAsJavaScriptException();
            return env.Null();
        }

        std::string inputPath = info[0].As<Napi::String>().Utf8Value();
        std::string outputPath = info[1].As<Napi::String>().Utf8Value();

        std::string extension = getFileExtension(outputPath);
        if (!isSupportedExtension(extension)) {
            Napi::Error::New(env, "Unsupported file extension: " + extension).ThrowAsJavaScriptException();
            return env.Null();
        }

        cv::Mat image = readImage(inputPath);
        if (image.empty()) {
            Napi::Error::New(env, "Could not open or find the image").ThrowAsJavaScriptException();
            return env.Null();
        }

        cv::Mat grayImage;
        cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

        // Check if saving the image works
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

double calculateSimilarity(const cv::Mat& image1, const cv::Mat& image2) {
    if (image1.size() != image2.size()) {
        throw std::invalid_argument("Images must have the same size to compare.");
    }

    cv::Mat diff;
    cv::absdiff(image1, image2, diff);

    cv::Mat diffSquared;
    cv::multiply(diff, diff, diffSquared);

    cv::Scalar s = cv::sum(diffSquared);
    double mse = s[0] + s[1] + s[2];

    double maxMSE = 255.0 * 255.0 * image1.total() * 3;

    double similarityPercentage = 100.0 - (mse / maxMSE * 100.0);

    return similarityPercentage;
}

Napi::Value compareImages(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    try {
        if (info.Length() < 2) {
            Napi::TypeError::New(env, "Expected two arguments").ThrowAsJavaScriptException();
            return env.Null();
        }

        std::string imagePath1 = info[0].As<Napi::String>().Utf8Value();
        std::string imagePath2 = info[1].As<Napi::String>().Utf8Value();

        cv::Mat image1 = readImage(imagePath1);
        cv::Mat image2 = readImage(imagePath2);

        if (image1.empty() || image2.empty()) {
            Napi::Error::New(env, "Could not open or find the images").ThrowAsJavaScriptException();
            return env.Null();
        }

        if (image1.size() != image2.size()) {
            if (image1.size().area() < image2.size().area()) {
                image1 = resizeToMatch(image1, image2);
            } else {
                image2 = resizeToMatch(image2, image1);
            }
        }

        double similarityPercentage = calculateSimilarity(image1, image2);

        bool areSimilar = (similarityPercentage >= 90.0);

        return Napi::Boolean::New(env, areSimilar);
    } catch (const cv::Exception& e) {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return env.Null();
    } catch (const std::exception& e) {
        Napi::Error::New(env, e.what()).ThrowAsJavaScriptException();
        return env.Null();
    }
}



// Initialize the module
Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "resizeImage"), Napi::Function::New(env, resizeImage));
    exports.Set(Napi::String::New(env, "grayscaleImage"), Napi::Function::New(env, grayscaleImage));
    exports.Set(Napi::String::New(env, "compareImages"), Napi::Function::New(env, compareImages));
    return exports;
}

NODE_API_MODULE(image_api, Init)
