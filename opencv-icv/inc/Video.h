#pragma once
#include <string>

class Video
{
private:
	std::string _videopath;
	std::string _windowsname;

public:
	Video(std::string videopath, std::string windowsname);
	~Video();

	void Play();
};