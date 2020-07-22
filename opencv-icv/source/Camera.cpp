#include "Camera.h"
#include <filesystem>
#include <opencv2/opencv.hpp>

Camera::Camera(std::string videoname, std::string windowsname) {
	this->_videoname = videoname;
	this->_windowsname = windowsname;
}

Camera::~Camera() {
	/* Do nothing */
}

void Camera::Open() {
	cv::Mat frame;
	cv::VideoCapture capture;
	capture.open(0);
	if (capture.isOpened()) {
		double dWidth = capture.get(cv::CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
		double dHeight = capture.get(cv::CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
		std::cout << "Resolution of the video : " << dWidth << " x " << dHeight << std::endl;

		cv::namedWindow(this->_windowsname, cv::WINDOW_KEEPRATIO);
		while (true) {
			capture >> frame; //bool flag = capture.read(frame);
			if (frame.empty()) {
				break;
			}

			cv::imshow(this->_windowsname, frame);

			//Wait for for 10 ms until any key is pressed.  
			//If the 'Esc' key is pressed, break the while loop.
			//If the any other key is pressed, continue the loop 
			//If any key is not pressed withing 10 ms, continue the loop 
			char ch = (char)cv::waitKey(10);
			if (ch == 27 /* Esc key */ || ch == 'q' || ch == 'Q') {
				cv::destroyWindow(this->_windowsname);
				break;
			}
		}
	}
	else {
		std::cout << "Failed to open the Camera" << std::endl;
	}
}

void Camera::Record() {
	cv::Mat frame;
	cv::VideoCapture capture;
	capture.open(0);
	if (capture.isOpened()) {
		double dWidth = capture.get(cv::CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
		double dHeight = capture.get(cv::CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
		std::cout << "Resolution of the video : " << dWidth << " x " << dHeight << std::endl;

		cv::namedWindow(this->_windowsname, cv::WINDOW_KEEPRATIO);

		std::string videopath = std::filesystem::current_path().string() + "\\resource\\";
		cv::VideoWriter store(videopath + this->_videoname, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 10, cv::Size((int)dWidth, (int)dHeight));
		while (true) {
			capture >> frame;
			if (frame.empty()) {
				break;
			}

			cv::imshow(this->_windowsname, frame);
			store.write(frame);

			//Wait for for 10 ms until any key is pressed.  
			//If the 'Esc' key is pressed, break the while loop.
			//If the any other key is pressed, continue the loop 
			//If any key is not pressed withing 10 ms, continue the loop 
			char ch = (char)cv::waitKey(10);
			if (ch == 27 /* Esc key */ || ch == 'q' || ch == 'Q') {
				cv::destroyWindow(this->_windowsname);
				break;
			}
		}
	}
	else {
		std::cout << "Failed to opemn Camera to record video" << std::endl;
	}
}