#pragma once
#include <string>

class Camera {
private:
	std::string _videoname; //For recorded video name
	std::string _windowsname;

public:
	Camera(std::string videoname, std::string windowsname);
	~Camera();

	void Open();

	void Record();
};