#pragma once
#include <string>

class Image {
private:
	std::string _imagepath;
	std::string _windowsname;

public:
	Image(std::string imagepath, std::string windowsname);
	~Image();
	void Load();
};