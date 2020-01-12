#include "FilterBlur.h"

image::Image image::FilterBlur::operator<<(const Image& image) {
	unsigned int width = image.getWidth();
	unsigned int height = image.getHeight();

	Image& in_image = const_cast<Image&>(image);
	Image filtered(width, height);

	//int m, n;
	//m = n = -this->N / 2;
	int limit = this->N / 2;
	std::cout << "hello" << std::endl;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; i++) {
			Color blur_pixel(0,0,0);
			for (int m = -N / 2; m < N / 2; m++) {
				for (int n = -N / 2 ; n < N / 2; n++) {
					int pixel_x = i + m;
					int pixel_y = j + n;

					// 0 <= i + m < w, 0 <= j + n < h
					if (pixel_x >= 0 && pixel_x < width && pixel_y >= 0 && pixel_y < height)
						blur_pixel += in_image.operator()(pixel_x, pixel_y) * operator()(m + (N / 2), n + (N / 2));
				}
			}
			filtered.operator()(i, j) = blur_pixel;
		}
	}
	return filtered;
}