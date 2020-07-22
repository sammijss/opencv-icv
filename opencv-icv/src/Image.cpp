#include "Image.h"
#include <opencv2/opencv.hpp>
//using namespace cv;

Image::Image(std::string imagepath, std::string windowsname) {
	this->_imagepath = imagepath;
	this->_windowsname = windowsname;
}

Image::~Image() {
	/* Do nothing */
}

void Image::Load() {
	// Read the image file
	cv::Mat image = cv::imread(this->_imagepath);
	if (image.empty()) { // Check for failure
		std::cout << "Could not open or find the image" << std::endl;
		return;
	}

	cv::namedWindow(this->_windowsname, cv::WINDOW_KEEPRATIO); // Create a window
	cv::imshow(this->_windowsname, image); // Show our image inside the created window.
	cv::waitKey(0); // Wait for any keystroke in the window
	cv::destroyWindow(this->_windowsname); //destroy the created window
}