#pragma once
#include <string>

class Image {
private:
	std::string _imagename;
	std::string _windowsname;

public:
	Image(std::string imagename, std::string windowsname);
	~Image();
	void Load();
};