#include <opencv2/opencv.hpp>

int main()
{
    // Load the cascade classifier for face detection
    cv::CascadeClassifier faceCascade;
    faceCascade.load("haarcascade_frontalface_default.xml");

    // Specify the path to the directory containing the images
    std::string imagesDirectory = "images/";

    // Get the list of image file names in the directory
    std::vector<std::string> imageFiles;
    cv::glob(imagesDirectory, imageFiles);

    // Process each image
    for (const std::string& imageFile : imageFiles)
    {
        // Load the image
        cv::Mat image = cv::imread(imageFile);
        if (image.empty())
        {
            std::cout << "Failed to load image: " << imageFile << std::endl;
            continue;
        }

        // Convert the image to grayscale
        cv::Mat grayImage;
        cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

        // Equalize the histogram to improve detection results
        cv::equalizeHist(grayImage, grayImage);

        // Detect faces in the grayscale image
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(grayImage, faces, 1.5, 4, 0, cv::Size(30, 30));

        // Process the detected faces
        if (faces.size() == 1)
        {
            // Draw a rectangle around the detected face
            cv::rectangle(image, faces[0], cv::Scalar(0, 255, 0), 2);
        }
        else
        {
            std::cout << "Failed to detect a single face in image: " << imageFile << std::endl;
        }

        // Display the image with the detected face
        cv::imshow("Face Detection", image);
        cv::waitKey(0);
    }

    return 0;
}