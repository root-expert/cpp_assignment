#pragma once

#ifndef _FILTER_
#define _FILTER_

#include "Image.h"

namespace image {
	class Filter
	{
	public:
		Filter() {}
		~Filter() {}

		virtual Image operator << (const Image & image) = 0;

	};
}

#endif // !_FILTER_

