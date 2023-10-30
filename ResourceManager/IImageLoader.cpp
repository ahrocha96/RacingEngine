#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "IImageLoader.h"
#include<iostream>

IImageLoader::IImageLoader() {

}

IImageLoader::~IImageLoader() {

}

void IImageLoader::LoadImage(const char* filename, int* width, int* height, int* channels, int req_comp) {
	
	unsigned char* imageData = stbi_load(filename, width, height, channels, req_comp);
	if (imageData) {
		std::cout << "Image Loaded Successfully" << std::endl;
		stbi_image_free(imageData);
	}
	else {
		std::cout << "Image failed to load" << std::endl;
	}

};