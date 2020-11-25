#include "algorythm/LoG.h"
#include <iostream>
#include <algorithm>

namespace Hasher {
	std::unique_ptr<std::vector<double>> LoG(int width, int height, double sigma) {
		std::vector<double> filter;
		int x, y, cx, cy;
		double sum = 0;

		// Use to allow suer to input width and height as just the lenght
		// and not the lenght from 0 to the edges.
		cx = width/2;
		cy = height/2;

		for(y=-cy; y<=cy; y++) {
			for(x=-cx; x<=cx; x++) {
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

	std::unique_ptr<std::vector<double>> transpose(std::vector<double> matrix, int row_size) {
		std::vector<double> res;
			
		for(int i = 0; i < row_size; i++) {
			for(int j = i; j < matrix.size(); j += row_size) {
				res.push_back(matrix[j]);
			}
		}
		return std::make_unique<std::vector<double>>(res);
	}

}
