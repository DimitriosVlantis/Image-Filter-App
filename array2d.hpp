// This assignment was done by:
// Bakalidis Vlantislav : 3180112
// Dimitrios Vlantis : 3180021

#ifndef _2D
#define _2D
#include "array2d.h"
#endif

template<typename T> 
const unsigned int math::Array2D<T>::getWidth() const {
	return width;
}

template<typename T>
const unsigned int math::Array2D<T>::getHeight() const {
	return height;
}

template<typename T>
T* math::Array2D<T>::getRawDataPtr()const{
	return (T*)buffer.data();
}

template<typename T>
void math::Array2D<T>::setData(const T* const& data_ptr) {
	if (data_ptr == nullptr) {
		return;
	}
	buffer.clear();
	for (unsigned int c = 0; c <= width * height - 1;c++) {
		buffer.push_back(data_ptr[c]);
	}
}

template<typename T>
T& math::Array2D<T>::operator () (unsigned int x, unsigned int y){
	return buffer[width*x+y];
}

template<typename T>
math::Array2D<T>::Array2D(unsigned int width, unsigned int height, const T* data_ptr) {
	this->width = width;
	this->height = height;
	buffer = std::vector<T>(width*height);
	if ((width * height != 0) & ((data_ptr != nullptr) | (data_ptr != 0))) {
		for (unsigned int c = 0; c <= width * height - 1; c++) {
			buffer[c] = data_ptr[c];
		}
	}
}

template<typename T>
math::Array2D<T>::Array2D(const Array2D& src) {
	this->width = src.getWidth();
	this->height = src.getHeight();
	buffer = std::vector<T>(src.getHeight()*src.getWidth());
	const T* tempData = src.getRawDataPtr();
	setData(tempData);
	delete[] tempData;
}

template<typename T>
math::Array2D<T>::~Array2D() {
	buffer.~vector();
}

template<typename T>
math::Array2D<T>& math::Array2D<T>::operator= (const math::Array2D<T>& right) {
	this->width = right.width;
	this->height = right.height;
	T* data_ptr = right.getRawDataPtr();
	buffer.clear();
	unsigned int i = 0;
	if (width * height != 0) {
		for (unsigned int c = 0; c <= width * height - 1; c++) {
			buffer.push_back(data_ptr[c]);
			i = c;
		}
	}
	//delete[] data_ptr;
	return *this;
}