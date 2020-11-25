#include "algorythm/Phash.h"
#include "core/Log.h"
#include "pre-cheader.h"
#include "algorythm/LoG.h"
#include "algorythm/DCT.h"
#include <iostream>
#include <exception>

namespace Hasher {

void phash(std::string file_path, double sigma) {

	int width, heigth;
	width = 5;
	heigth = 5;

	std::unique_ptr<std::vector<double>> kernel(LoG(width, heigth, sigma));
	std::unique_ptr<std::vector<double>> dct_kernel(DCT(8,8));

	std::vector<double> krn = *kernel;
	std::vector<double> dct = *dct_kernel;
	std::unique_ptr<std::vector<double>> ptr_test;

	std::vector<double> test = { 1, 2 ,3, 4 ,5 ,6 };

	std::unique_ptr<std::vector<double>> trans_dct(transpose(dct, 8));

	CORE_INFO((*dct_kernel).size());
	for(int i = 0; i < (*dct_kernel).size(); i++) {
		if(i % 8 == 0)
			std::cout << "\n";
		std::cout << (*dct_kernel)[i] << ", ";
	}
	std::cout << "\n";

	for(int i = 0; i < test.size(); i++) {
		if(i % 3 == 0)
			std::cout << "\n";
		std::cout << test[i] << ", ";
	}
	std::cout << "\n";

	ptr_test = transpose(test, 3);
	for(int i = 0; i < (*ptr_test).size(); i++) {
		if(i % 2 == 0)
			std::cout << "\n";
		std::cout << (*ptr_test)[i] << ", ";
	}
	std::cout << "\n";
	try {
		Magick::Image master(file_path);
		master.type(Magick::GrayscaleType);
		master.convolve(width, &krn[0]); 
		master.resize("32x32!");
		master.convolve(8, &(*dct_kernel)[0]);
		master.resize("128x128!");
		master.display();
	} catch (std::exception& error_) {
		CORE_ERROR(error_.what());
	}
}

}
