import cppAddon from './loadAddon.js';

export function resizeImage(inputPath, outputPath) {
  const result = cppAddon.resizeImage(inputPath, outputPath);
  if (result) {
    console.log('Image resized successfully!');
  } else {
    console.log('Failed to resize the image.');
  }
}

export function grayscaleImage(inputPath, outputPath) {
  const result = cppAddon.grayscaleImage(inputPath, outputPath);
  if (result) {
    console.log('Image converted to grayscale successfully!');
  } else {
    console.log('Failed to convert the image to grayscale.');
  }
}

export function compareImages(imagePath1, imagePath2) {
  const result = cppAddon.compareImages(imagePath1, imagePath2);
  if (result) {
    console.log('The images are similar!');
  } else {
    console.log('The images are not similar.');
  }
}
