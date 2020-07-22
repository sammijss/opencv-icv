#pragma once
#include <string>

class Video
{
private:
	std::string _videoname;
	std::string _windowsname;

public:
	Video(std::string videoname, std::string windowsname);
	~Video();

	void Play();
};