#!/usr/bin/env node

import { resizeImage, grayscaleImage, compareImages } from './index.js';

const args = process.argv.slice(2);

if (args.length >= 3) {
  const inputPath = args[0];
  const outputPath = args[1];

  if (args[2] === 'grayscale') {
    // Ensure grayscale is used with two arguments (input and output paths)
    if (args.length === 3) {
      const result = grayscaleImage(inputPath, outputPath);
      if (result) {
          console.log('Image converted to grayscale successfully!');
        } else {
          console.log('Failed to convert the image to grayscale.');
        }
    } else {
      console.error("For grayscale, two arguments (input and output paths) are required.");
    }
  } else if (args[2] === 'compare') {
    // Ensure we have exactly 3 arguments (input, second image, 'compare')
    const secondImagePath = args[1];
    const result = compareImages(inputPath, secondImagePath);
    console.log(result)
    if (result) {
      console.log('The images are similar!');
    } else {
      console.log('The images are not similar.');
    }
  } else {
    // Default case: resize image
    const result = resizeImage(inputPath, outputPath);
    if (result) {
      console.log('Image resized successfully!');
    } else {
      console.log('Failed to resize the image.');
    }
  }
} else {
  console.log(`
Usage: image-tool <inputPath> <outputPath|secondImagePath> [grayscale|compare] 

Available Commands:
  1. **Resize an image** (default):
     Usage: image-tool <inputPath> <outputPath>
     - Resizes the input image and saves it to the output path.

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
  `);
  process.exit(1);
}
