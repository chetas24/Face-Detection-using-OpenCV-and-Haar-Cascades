# Face Detection using OpenCV and Haar Cascades

This project demonstrates face detection using OpenCV library and Haar cascade classifiers. It includes a simple C++ code that processes a collection of images, detects faces, and visualizes the results.

## Description

The face detection algorithm is implemented using the following steps:

1. Loading Cascade Classifier: The code loads a pre-trained Haar cascade classifier for face detection from the XML file "haarcascade_frontalface_default.xml".

2. Image Processing: Each image in the specified directory is loaded and processed:
   - Conversion to Grayscale: The image is converted to grayscale to simplify further processing.
   - Histogram Equalization: The histogram of the grayscale image is equalized to enhance contrast and improve detection results.

3. Face Detection: The processed grayscale image is passed through the faceCascade classifier using the `detectMultiScale` function. Detected faces are stored as rectangles in the `faces` vector.

4. Visualization: If a single face is detected in the image, a green rectangle is drawn around the face using the `rectangle` function.

5. Image Display: The processed image with the detected face (if any) is displayed, and the program waits for a key press before proceeding to the next image.

## Getting Started

### Prerequisites

- OpenCV library (version 4.6.0 or above) needs to be installed. You can find installation instructions on the official OpenCV website.

### Installation and Usage

1. Clone the repository:
https://github.com/chetas24/Face-Detection-using-OpenCV-and-Haar-Cascades.git

2. Compile the code using a C++ compiler with OpenCV library linked.

3. Place your images in the "images" directory.

4. Run the compiled executable.

## Example Results

The code processes each image in the "images" directory, performs face detection, and displays the images with detected faces.

## Contributing

Contributions are welcome! If you have any improvements or suggestions, please submit a pull request or open an issue.

## Acknowledgments

- The Haar cascade classifier used for face detection is provided by OpenCV.
- The code is inspired by OpenCV tutorials and samples.
