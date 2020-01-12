#include <iostream>

template <typename T>
math::Array2D<T>::Array2D(unsigned int width, unsigned int height, const T* data_ptr) {
	this->width = width;
	this->height = height;

	if (width != 0 && height != 0)
		buffer.resize(width * height);
	setData(data_ptr);
	
}

template <typename T>
math::Array2D<T>::Array2D(const Array2D& src) {
	this->width = src.getWidth();
	this->height = src.getHeight();
	this->buffer = src.buffer;
}

template <typename T>
math::Array2D<T>::~Array2D() {}

template <typename T> 
const unsigned int math::Array2D<T>::getWidth() const {
	return this->width;
}

template <typename T>
const unsigned int math::Array2D<T>::getHeight() const {
	return this->height;
}

template <typename T>
T* math::Array2D<T>::getRawDataPtr() {
	return buffer.data();
}

template <typename T>
void math::Array2D<T>::setData(const T* const& data_ptr) {
	if (this->height != 0 && this->width != 0) {
		try {
			// Initilize with zero.
			if (data_ptr == 0) 
				buffer = std::vector<T>(width * height, 0);
			else 
				memcpy(buffer.data(), data_ptr, width*height);
		}
		catch (std::bad_alloc & ba) {
			std::cerr << "Could not allocate the requested storage space!" << ba.what() << std::endl;
		}
	}
}

template <typename T>
T& math::Array2D<T>::operator () (unsigned int x, unsigned int y) {
	return buffer.at(x * this->height + y);
}	

template <typename T>
math::Array2D<T>& math::Array2D<T>::operator = (const math::Array2D<T>& right) {
	if (!buffer.empty())
		buffer.clear();
	this->height = right.height;
	this->width = right.width;
	this->buffer = right.buffer;

	return *this;
}