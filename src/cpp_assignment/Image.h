#pragma once

#ifndef _IMAGE
#define _IMAGE

#include "array2d.h"
#include "vec3.h"
#include "imageio.h"

typedef math::Vec3<float> Color;

namespace image {
	class Image : public ImageIO, public math::Array2D<Color>
	{
	public:
		Image();
		Image(const Image &image);
		Image(unsigned int width, unsigned int height);
		~Image();

		virtual bool load(const std::string& filename, const std::string& format);
		virtual bool save(const std::string& filename, const std::string& format);
	};

}

#endif

