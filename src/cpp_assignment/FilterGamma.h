#pragma once
#include "Filter.h"

namespace image {
	class FilterGamma : public Filter
	{
		float gamma;

	public:
		FilterGamma() : Filter() {}
		FilterGamma(float gamma) : gamma(gamma) {}
		FilterGamma(const FilterGamma &src): gamma(src.gamma) {}
		~FilterGamma() {}

		Image operator<< (const Image& image);
	};

}

