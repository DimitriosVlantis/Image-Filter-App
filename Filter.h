// This assignment was done by:
// Bakalidis Vlantislav : 3180112
// Dimitrios Vlantis : 3180021

#ifndef __FILTER
#define __FILTER
#include "Image.h"

class Filter {
public:
	virtual Image operator << (const Image& image) = 0;
};

#endif