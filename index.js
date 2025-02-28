import cppAddon from './loadAddon.js';

export function resizeImage(inputPath, outputPath, zoom='2') {
  return cppAddon.resizeImage(inputPath, outputPath, zoom);
}

export function grayscaleImage(inputPath, outputPath) {
  return cppAddon.grayscaleImage(inputPath, outputPath);
}

export function compareImages(imagePath1, imagePath2) {
  return cppAddon.compareImages(imagePath1, imagePath2);
}
