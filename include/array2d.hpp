#include <iostream>

template <typename T>
math::Array2D<T>::Array2D(unsigned int width, unsigned int height, const T* data_ptr) {
	this->width = width;
	this->height = height;
	setData(data_ptr);

}

template <typename T>
math::Array2D<T>::Array2D(const Array2D& src) {
	this->width = src.getWidth();
	this->height = src.getHeight();
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
			memcpy(&buffer, data_ptr, width * height);
			/*int size = this->width * this->height;
			T* vec = new T(*data_ptr);
			for (int i = 0; i <= size; i++) {
				buffer.push_back(vec);
			} */
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
	this->height = right.height;
	this->width = right.width;
	this->buffer.resize(this->width, this->height);
	this->buffer = right.buffer;

	return *this;
}