#pragma once
#include <opencv2/opencv.hpp>

class Camera {
private:
	std::string _windowsname;

public:
	Camera(std::string windowsname);
	~Camera();

	void Open();

	void Record();
};