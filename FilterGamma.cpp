// This assignment was done by:
// Bakalidis Vlantislav : 3180112
// Dimitrios Vlantis : 3180021

#include "vec3.h"
#include "Filter.h"
#include "Image.h"
#include <iostream>

class FilterGamma:Filter {
private:
	float y;
public:
	FilterGamma() {
		y = 1.0f;
	}

	FilterGamma(float y) {
		this->y = y;
	}
	
	FilterGamma(FilterGamma& ftg) {
		this->y = ftg.y;
	}

	FilterGamma& operator= (const FilterGamma& ftg) {
		y = ftg.y;
		return *this;
	}
	
	~FilterGamma() {
		//Nothing
	}

	 Image operator << (const Image& image) {
		 math::Vec3<float>* vec3ptr = image.getRawDataPtr();
		 for (unsigned int i = 0; i <= image.getWidth()*image.getHeight()-1; i++) {
			 vec3ptr[i].r = pow(vec3ptr[i].r,y);
			 vec3ptr[i].g = pow(vec3ptr[i].g, y);
			 vec3ptr[i].b = pow(vec3ptr[i].b, y);
			 vec3ptr[i] = vec3ptr[i].clampToUpperBound(1.0f).clampToLowerBound(0.0f);
		 }
		 Image tempimage = Image();
		 tempimage = image;
		 return tempimage;
	 }
};