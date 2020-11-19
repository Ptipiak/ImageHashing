#include "algorythm/LoG.h"
#include <math.h>
#include <iostream>
#include <vector>

namespace Hasher {
	std::unique_ptr<std::vector<double>> LoG(int width, int height, double sigma) {
		std::vector<double> filter;
		int x, y;
		double sum = 0;

		for(y=-height; y<=height; y++) {
			for(x=-width; x<=width; x++) {
				/* filter.push_back(1/pow(2*M_PI*sigma, 2.0)); */
				/* filter.back() = filter.back()*exp(-((pow(x, 2.0)+pow(y, 2.0))/2*(pow(sigma, 2.0)))); */
				filter.push_back(exp(-(x*x+y*y)/(2*sigma*sigma))/(2*M_PI*sigma*sigma));
				sum += filter.back();
				/* std::cout << y << "," << x << ", "; */
				std::cout << filter.back() << ", ";
			}
			std::cout << "\n";
		}

		std::vector<double>::iterator it;
		for(it=filter.begin(); it < filter.end(); it++) {
			*it /= sum;
		}
		return std::make_unique<std::vector<double>>(filter);
	}
}
