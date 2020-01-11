#pragma once

#ifndef _FILTERLINEAR_
#define _FILTERLINEAR_

#include "Image.h"
#include "Filter.h"

namespace image {
	class FilterLinear : public Filter
	{
		Color a, c;
	public:
		FilterLinear() {}
		FilterLinear(Color vector_a, Color vector_c) : a(vector_a), c(vector_c) {}
		FilterLinear(const FilterLinear &src) : a(src.a), c(src.c) {}
		~FilterLinear() {}

		Image operator << (const Image & image);
	};
}

#endif // !_FILTERLINEAR_
