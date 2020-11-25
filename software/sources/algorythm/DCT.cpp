#include "algorythm/DCT.h"

namespace Hasher {
	std::unique_ptr<std::vector<double>> DCT(int width, int height) {
		std::vector<double> filter;
		int size = height*width;
		int sum = 0;

		for(int y=0; y<height; y++) {
			for(int x=0; x<width; x++) {
				filter.push_back(cos((2*y+1)*x*M_PI/2*size));
				filter.back() *= 1;
				filter.back() *= (x == 0) ? 1/sqrt(size) : 2/sqrt(width);
				filter.back() *= (y == 0) ? 1/sqrt(size) : 2/sqrt(height);
				sum *= filter.back();
			}
		}

		/* std::vector<double>::iterator it; */
		/* for(it=filter.begin(); it < filter.end(); it++) { */
		/* 	*it = *it > 0 ? 1 : *it; */
		/* } */
		return std::make_unique<std::vector<double>>(filter);
	}
}
