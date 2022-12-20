// This assignment was done by:
// Bakalidis Vlantislav : 3180112
// Dimitrios Vlantis : 3180021

#include "Filter.h"
#include <iostream>

class FilterLinear :Filter {
private:
	float aR, aG, aB;
	float cR, cG, cB;

public:
	FilterLinear() {
		this->aR = 1.0f;
		this->aG = 1.0f;
		this->aB = 1.0f;
		this->cR = 0.0f;
		this->cG = 0.0f;
		this->cB = 0.0f;
	}

	FilterLinear(float aR,float aG,float aB,float cR,float cG, float cB) {
		this->aR = aR;
		this->aG = aG;
		this->aB = aB;
		this->cR = cR;
		this->cG = cG;
		this->cB = cB;
	}

	FilterLinear(FilterLinear& ftl) {
		this->aR = ftl.aR;
		this->aG = ftl.aG;
		this->aB = ftl.aB;
		this->cR = ftl.cR;
		this->cG = ftl.cG;
		this->cB = ftl.cB;
	}

	FilterLinear& operator= (const FilterLinear& ftl) {
		this->aR = ftl.aR;
		this->aG = ftl.aG;
		this->aB = ftl.aB;
		this->cR = ftl.cR;
		this->cG = ftl.cG;
		this->cB = ftl.cB;
		return *this;
	}

	~FilterLinear() {
		//Nothing
	}

	Image operator << (const Image& image) {
		math::Vec3<float> a(aR, aG, aB);
		math::Vec3<float> c(cR, cG, cB);
		math::Vec3<float>* vec3ptr = image.getRawDataPtr();
		for (unsigned int i = 0; i <= image.getWidth() * image.getHeight() - 1; i++) {
			vec3ptr[i] *= a;
			if (vec3ptr[i].r > 1.0f) {
				vec3ptr[i].r = 1.0f;
			}
			if (vec3ptr[i].g > 1.0f) {
				vec3ptr[i].g = 1.0f;
			}
			if (vec3ptr[i].b > 1.0f) {
				vec3ptr[i].b = 1.0f;
			}
			if (vec3ptr[i].r < 0.0f) {
				vec3ptr[i].r = 1.0f;
			}
			if (vec3ptr[i].g < 0.0f) {
				vec3ptr[i].g = 1.0f;
			}
			if (vec3ptr[i].b < 0.0f) {
				vec3ptr[i].b = 1.0f;
			}
			vec3ptr[i] += c;
			if (vec3ptr[i].r > 1.0f) {
				vec3ptr[i].r = 1.0f;
			}
			if (vec3ptr[i].g > 1.0f) {
				vec3ptr[i].g = 1.0f;
			}
			if (vec3ptr[i].b > 1.0f) {
				vec3ptr[i].b = 1.0f;
			}
			if (vec3ptr[i].r < 0.0f) {
				vec3ptr[i].r = 1.0f;
			}
			if (vec3ptr[i].g < 0.0f) {
				vec3ptr[i].g = 1.0f;
			}
			if (vec3ptr[i].b < 0.0f) {
				vec3ptr[i].b = 1.0f;
			}
		}
		Image tempimage = Image();
		tempimage = image;
		return tempimage;
	}
};