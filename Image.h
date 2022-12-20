// This assignment was done by:
// Bakalidis Vlantislav : 3180112
// Dimitrios Vlantis : 3180021

#ifndef __IMAGE
#define __IMAGE
#include "imageio.h"
#include "vec3.h"
#include "array2d.h"
#include <string>

class Image :public math::Array2D<math::Vec3<float>>,image::ImageIO {

public:

	bool load(const std::string& filename, const std::string& format);

	bool save(const std::string& filename, const std::string& format);

	Image(unsigned int width=0, unsigned int height=0, const math::Vec3<float>* data_ptr=0);

	~Image();

	//Image& operator= (const Image& image);
};

#endif