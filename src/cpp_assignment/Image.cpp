#include "Image.h"
#include "ppm/ppm.h"

image::Image::Image() : Array2D<Color>() {}
image::Image::Image(const Image &image) : Array2D<Color>(image) {}
image::Image::Image(int width, int height) : Array2D<Color>(width, height) {}
image::Image::~Image() {}

bool image::Image::load(const std::string& filename, const std::string& format) {
	// Only ppm format is supported
	if (format.compare(".ppm") != 0) {
		std::cerr << "Only .ppm format is allowed!" << std::endl;
		return false;
	}
	
	int width, height;
	float* data = image::ReadPPM((filename + format).c_str(), &width, &height);

	if (data == nullptr)
		return false;
		
	this->width = width;
	this->height = height;
	int size = 3 * width * height;
	
	buffer.reserve(width * height);
	for (int i = 0; i < size; i = i + 3) {
		math::Vec3<float> pixel(data[i], data[i + 1], data[i + 2]);
		buffer.push_back(pixel);
	}

	return true;
}

bool image::Image::save(const std::string& filename, const std::string& format) {
	// Only .ppm format is supported
	if (format.compare(".ppm") != 0) {
		std::cerr << "Only .ppm format is allowed!" << std::endl;
		return false;
	}

	int width = getWidth();
	int height = getHeight();
	float* temp = new float[3 * width * height];

	int i = 0;
	for (std::vector<Color>::iterator k = buffer.begin(); k != buffer.end(); k++, i = i + 3) {
		temp[i] = k->x;
		temp[i + 1] = k->y;
		temp[i + 2] = k->z;
	}

	bool saved = WritePPM(temp, width, height, (filename + format).c_str());

	if (!saved)
		return false;

	return true;
}