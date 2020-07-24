#include "Image.h"
#include "Camera.h"
#include "Video.h"
#include <iostream>

int main() {
	char ch; /* char for option */

	do {
		std::cout << "Enter your choice Image(i), Camera(c) Video(v), Recording(r) Exit(e): ";
		std::cin >> ch;
		switch (ch) {
		case 'i':
		case 'I':
		{
			/* IMAGE PROCESSING */
			Image imageobj("OpenCVImage.png", "OpenCV-Image");
			imageobj.Load();
		}
		break;
		case 'c':
		case 'C':
		{
			/* CAMERA PROCESSING */
			Camera cameraobj(std::string(), "OpenCV-Camera");
			cameraobj.Open();
		}
		break;
		case 'r':
		case 'R':
		{
			/* CAMERA PROCESSING */
			Camera cameraobj("OpenCVRecording.mp4", "OpenCV-Recording");
			cameraobj.Record();
		}
		break;
		case 'v':
		case 'V':
		{
			/* VIDEO PROCESSING */
			Video videoobj("OpenCVVideo.mp4", "OpenCV-Video");
			videoobj.Play();
		}
		break;
		default:
		{
			std::cout << "Invalid option, use 'e' to exit" << std::endl;
		}
		}
	} while (ch != 'e' && ch != 'E');
	return (0);
}