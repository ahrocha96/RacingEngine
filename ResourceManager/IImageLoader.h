#pragma once

class IImageLoader
{
public:
	IImageLoader();
	virtual ~IImageLoader();
	virtual void LoadImage(const char* filename, int* width, int* height, int* channels, int req_comp);
private:
};

