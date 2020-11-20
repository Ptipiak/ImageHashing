#include "algorythm/Phash.h"
#include "core/Log.h"
#include "pre-cheader.h"
#include "algorythm/LoG.h"
#include <iostream>
#include <exception>

namespace Hasher {

void phash(std::string file_path, double sigma) {

	std::unique_ptr<std::vector<double>> kernel_(LoG(3, 3, sigma));

	std::vector<double> var = *kernel_;
	for(int i = 0; i < var.size(); i++) {
		if(i % 7 == 0)
			std::cout << "\n";
		std::cout << var[i] << ", ";
	}
	std::cout << "\n";

	/* CORE_INFO("Result of Laplacian of Gaussien {}", msg); */

	try {
		Magick::Image master(file_path);
		master.type(Magick::GrayscaleType);
		master.convolve(7, &var[0]); 
		/* master.resize("32x32!"); */
		master.display();
	} catch (std::exception& error_) {
		CORE_ERROR(error_.what());
	}
}

}
