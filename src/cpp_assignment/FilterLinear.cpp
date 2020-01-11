#include "FilterLinear.h"

image::Image image::FilterLinear::operator<<(const Image & image) {
	std::cout << "hi" << std::endl;
	int width = image.getWidth();
	int height = image.getHeight();

	/* const_cast the argument. We are not gonna change it
	 * just read the pixels. Overloaded () operator function
	 * is not const so we can call it directly.
	 */
	Image& new_image = const_cast<Image&>(image);
	Image filtered(width, height);
	//filtered.setData(new_image.getRawDataPtr());
	std::cout << "hi2" << std::endl;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			Color new_pixel(a * new_image.operator()(i, j) + c);

			// RGB should be between [0,1]
			if (new_pixel.x < 0)
				new_pixel.x = 0;
			if (new_pixel.x > 1)
				new_pixel.x = 1;

			if (new_pixel.y < 0)
				new_pixel.y = 0;
			if (new_pixel.y > 1)
				new_pixel.y = 1;

			if (new_pixel.z < 0)
				new_pixel.z = 0;
			if (new_pixel.z > 1)
				new_pixel.z = 1;
			std::cout << "hi3" << std::endl;
			filtered.operator()(i, j) = new_pixel;
			std::cout << "hi4" << std::endl;
		}
	}
	return filtered;
}
