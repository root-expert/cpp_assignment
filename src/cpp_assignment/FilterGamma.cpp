#include "FilterGamma.h"

image::Image image::FilterGamma::operator<<(const Image& image) {
	int width = image.getWidth();
	int height = image.getHeight();

	Image& new_image = const_cast<Image&>(image);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			Color old_pixel = new_image.operator()(i, j);
			Color new_pixel(pow(old_pixel.x, gamma), pow(old_pixel.y, gamma), pow(old_pixel.z, gamma));

			new_image.operator()(i, j) = new_pixel;
		}
	}
	return new_image;
}
