// This assignment was done by:
// Bakalidis Vlantislav : 3180112
// Dimitrios Vlantis : 3180021

#include "Image.h"
#include "Filter.h"
#include "FilterGamma.cpp"
#include "FilterLinear.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	char* filename = argv[argc - 1];
	string filename_s = filename;
	Image image = Image();
	image.load(filename, "ppm");
	string curParam; //current parameter
	bool linear = false;
	bool gamma = false;
	float y;
	float aR, aG, aB;
	float cR, cG, cB;
	FilterGamma filGamma;
	FilterLinear filLinear;
	for (int c = 1;c <= argc-2; c++) {
		curParam = argv[c];
		cout <<"This is the curParam  " << curParam << endl;
		if (curParam.compare("-f") == 0) {
			continue;
		}
		else if (curParam.compare("gamma") == 0) {
			gamma = true;
			continue;
		}
		else if (curParam.compare("linear") == 0) {
			linear = true;
			continue;
		}
		if (gamma) {
			y = strtof(curParam.c_str(),0);
			filGamma = FilterGamma(y);
			image = (filGamma << image);
			gamma = false;
		}
		if(linear) {
			aR = strtof(curParam.c_str(), 0);
			c++;
			curParam = argv[c];
			aG = strtof(curParam.c_str(), 0);
			c++;
			curParam = argv[c];
			aB = strtof(curParam.c_str(), 0);
			c++;
			curParam = argv[c];
			cR = strtof(curParam.c_str(), 0);
			c++;
			curParam = argv[c];
			cG = strtof(curParam.c_str(), 0);
			c++;
			curParam = argv[c];
			cB = strtof(curParam.c_str(), 0);

			filLinear = FilterLinear(aR,aG,aB,cR,cG,cB);
			image = (filLinear << image);
			linear = false;
		}
	}
	image.save("filtered_"+filename_s, "ppm");
	//delete[] filename;
	cout << "THIS PROGRAM HAS BEEN SPONSORED BY RAID:SHADOW LEGENDS!\n";
	return 0;
}