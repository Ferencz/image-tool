# Image Tool

A versatile Node.js application for basic image processing tasks such as resizing images, converting images to grayscale, and comparing images for similarity. This project leverages native bindings for high-performance operations.

## Features

- **Resize Images**: Resize images to half their original size.
- **Grayscale Conversion**: Convert images to grayscale.
- **Image Comparison**: Compare two images for similarity.

## Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/Ferencz/image-tool.git
   cd image-tool
   ```

2. **Install Dependencies:**
   ```bash
   npm install
   ```

3. **Build the Project:**
   ```bash
   ./build.sh
   ```

### Building the Project

If you encounter issues with the OpenCV installation, ensure that OpenCV is correctly installed on your system and that the paths to the headers and libraries are correctly specified in the `binding.gyp` file.

## Usage

### Command-Line Interface

After installation, you can use the tool directly from the command line using the `image-tool` command.

1. **Resizing an Image:**
   ```bash
   image-tool path/to/your/input/image.jpg path/to/your/output/image_resized.jpg
   ```

2. **Converting an Image to Grayscale:**
   ```bash
   image-tool path/to/your/input/image.jpg path/to/your/output/image_gray.jpg grayscale
   ```

3. **Comparing Two Images:**
   ```bash
   image-tool path/to/your/image1.jpg path/to/your/image2.jpg compare
   ```

4. **Help Page**
```bash
Usage: image-tool <inputPath> <outputPath|secondImagePath> [grayscale|compare] 

Available Commands:
  1. **Resize an image** (default):
     Usage: image-tool <inputPath> <outputPath> [n]
     - Resizes by n number of times default = 2 the input image and saves it to the output path.

  2. **Convert image to grayscale**:
     Usage: image-tool <inputPath> <outputPath> grayscale
     - Converts the input image to grayscale and saves it to the output path.

  3. **Compare two images for similarity**:
     Usage: image-tool <inputPath> <secondImagePath> compare
     - Compares the two images and returns 'true' if they are similar (pixel-by-pixel comparison).
     
Example usage:
  - Resize image:    image-tool image.png resized_image.png
  - Grayscale image: image-tool image.png grayscale_image.png grayscale
  - Compare images:  image-tool image1.png image2.png compare
  ```

### As a Module

You can also use this package as a module in a Node.js project that uses ES6 modules.

1. **Install the Package:**
   If the package is published to npm, you can install it using:
   ```bash
   npm install image-tool
   ```

   Otherwise, you can link it locally:
   ```bash
   npm install path/to/your/local/image-tool
   ```

2. **Import and Use in Your Project:**
   ```js
   import { resizeImage, grayscaleImage, compareImages } from 'image-tool';

   // Example Usage
   const inputPath = 'path/to/input/image.jpg';
   const outputPathResized = 'path/to/output/image_resized.jpg';
   const outputPathGray = 'path/to/output/image_gray.jpg';
   const secondImagePath = 'path/to/second/image.jpg';

   // Resize Image
   resizeImage(inputPath, outputPathResized);

   // Convert Image to Grayscale
   grayscaleImage(inputPath, outputPathGray);

   // Compare Images
   compareImages(inputPath, secondImagePath);
   ```

## Development

### Modifying the Build

If you need to modify the build configuration, update the `binding.gyp` file and run the build script:

```bash
./build.sh
```

### Testing the library
Write your own tests in the `package.json` 
```json
{
   ...
   "scripts": {
     "test": "echo \"Run all tests\" && ./tests/test.sh",
     ...
     "test:newtest": "...."
   }
}
```
and update the `tests/test.sh` to include the new test `npm run test:newtest`

```bash
npm run test

> image-tool@1.0.0 test
> echo "Run all tests" && ./tests/test.sh

Run all tests
=============

> image-tool@1.0.0 test:rescale
> node app.js tests/testImage.png tests/testImagesmaller-x2.png

Image resized successfully! 2 times
===================================

> image-tool@1.0.0 test:rescale3
> node app.js tests/testImage.png tests/testImagesmaller-x3.png 3

Image resized successfully! 3 times
===================================

> image-tool@1.0.0 test:grayscale
> node app.js tests/secondTestImage.png tests/secondTestImage-gray.png grayscale

Image converted to grayscale successfully!
==========================================

> image-tool@1.0.0 test:compare
> node app.js tests/testImage.png tests/testImagesmaller-x2.png compare

{ grayscaleComparison: 1, colorComparison: 1, averageComparison: 1 }
The images are similar!
=======================

> image-tool@1.0.0 test:comparef
> node app.js tests/secondTestImage.png tests/testImage.png compare

{
  grayscaleComparison: 0.11160479048459677,
  colorComparison: 0.08439103955461331,
  averageComparison: 0.09799791501960504
}
The images are not similar.
===========================
```

### Contributions

Contributions are welcome! Feel free to fork the repository and submit pull requests.

## License

This project is provided "as is," without any warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the author or copyright holders be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in the software.

The software is free for use by the user as they see fit.  The author is not liable for how the software is used.
