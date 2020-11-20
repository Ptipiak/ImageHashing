#include "algorythm/LoG.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <stdexcept>

namespace Hasher {
	std::unique_ptr<std::vector<double>> LoG(int width, int height, double sigma) {
		std::vector<double> filter;
		int x, y;
		double sum = 0;

		for(y=-height; y<=height; y++) {
			for(x=-width; x<=width; x++) {
				filter.push_back(x*x+y*y-2*sigma*sigma/pow(sigma, 4));
				filter.back() = filter.back() * exp(-(x*x+y*y)/(2*sigma*sigma))/(2*M_PI*sigma*sigma);
				sum += filter.back();
			}
		}

		std::vector<double>::iterator it;
		for(it=filter.begin(); it < filter.end(); it++) {
			*it /= sum;
		}
		return std::make_unique<std::vector<double>>(filter);
	}
}
