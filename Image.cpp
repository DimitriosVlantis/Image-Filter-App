// This assignment was done by:
// Bakalidis Vlantislav : 3180112
// Dimitrios Vlantis : 3180021

#include <iostream>
#include "Image.h"
#include "vec3.h"
#include "ppm.h"
using namespace std;
using namespace image;

inline bool caseInsCharCompareN(char a, char b) {
	return(toupper(a) == toupper(b));
}

bool caseInsCompare(const string & s1, const string & s2) {
	return((s1.size() == s2.size()) && equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareN));
}

bool Image::load(const std::string& filename, const std::string& format) {
	if (!caseInsCompare(format,"ppm")) {
		cout << "Invalid Format" << endl;
		return false;
	}
	int w = 0;
	int h = 0;
	int* pw = &w;
	int* ph = &h;
	const char* filenameptr = filename.c_str();
	float* picture = ReadPPM(filenameptr, pw, ph);
	math::Vec3<float>* Ipicture = new math::Vec3<float>[(*pw)*(*ph)];
	int i = 0;
	for (int c = 0; c <= 3 * (*pw) * (*ph) - 1; c += 3) {
		Ipicture[i].r = picture[c];
		Ipicture[i].g = picture[c + 1];
		Ipicture[i].b = picture[c + 2];
		i++;
	}
	this->height = (*ph);
	this->width = (*pw);
	vector< math::Vec3<float> > resizer = vector< math::Vec3<float> >(width*height);
	buffer = resizer;
	setData(Ipicture);

	//delete[] filenameptr;
	delete[] picture;
	delete[] Ipicture;
	return true;
}

bool Image::save(const std::string& filename, const std::string& format) {
	if (!caseInsCompare(format, "ppm")) {
		cout << "Invalid Format" << endl;
		return false;
	}
	float* picture = new float[width*height * 3];
	int i = 0;
	for (unsigned int c = 0;c <= 3 * width*height -1; c+=3) {
		picture[c] = buffer[i].r;
		picture[c+1] = buffer[i].g;
		picture[c+2] = buffer[i].b;
		i++;
	}
	const char* filenameptr = filename.c_str();
	WritePPM(picture,width,height, filenameptr);
	//delete[] filenameptr;
	//delete[] picture;
	return true;
}

Image::Image(unsigned int width, unsigned int height, const math::Vec3<float>* data_ptr) :Array2D(width, height, data_ptr) {

}

Image::~Image(){

}