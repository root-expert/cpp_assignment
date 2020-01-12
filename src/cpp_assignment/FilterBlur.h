#pragma once

#include "Filter.h"

namespace image {
	class FilterBlur : public Filter, math::Array2D<float>
	{
		int N;

	public:
		FilterBlur() : Filter(), N(0) {}

		FilterBlur(int N): Filter(), math::Array2D<float>(N, N), N(N) {
			// Every cell has 1/N^2 value
			float value = 1.0f / float(N * N);
			std::cout << "value = " << value << std::endl;

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					this->operator()(i, j) = value;
				}
			}
		}

		FilterBlur(const FilterBlur& src) : FilterBlur(src.N) {}
		~FilterBlur() {}

		Image operator<< (const Image& image);
	};

}

