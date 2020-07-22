#include "Image.h"
#include <filesystem>
#include <opencv2/opencv.hpp>
//using namespace cv;

Image::Image(std::string imagename, std::string windowsname) {
	this->_imagename = imagename;
	this->_windowsname = windowsname;
}

Image::~Image() {
	/* Do nothing */
}

void Image::Load() {
	std::string imagepath = std::filesystem::current_path().string() + "\\resource\\";
	// Read the image file
	cv::Mat image = cv::imread(imagepath + this->_imagename);
	if (image.empty()) { // Check for failure
		std::cout << "Could not open or find the image" << std::endl;
		return;
	}

	cv::namedWindow(this->_windowsname, cv::WINDOW_KEEPRATIO); // Create a window
	cv::imshow(this->_windowsname, image); // Show our image inside the created window.
	cv::waitKey(0); // Wait for any keystroke in the window
	cv::destroyWindow(this->_windowsname); //destroy the created window
}