#include "algorythm/Phash.h"
#include "core/Log.h"
#include "pre-cheader.h"
#include "algorythm/LoG.h"
#include <exception>

namespace Hasher {

void phash(std::string file_path) {

	double kernel_[] = {
		 0.0,  1.0,  0.0,
		 1.0, -4.0,  1.0,
		 0.0,  1.0,  0.0
	};
	std::unique_ptr<std::vector<double>> kernel_test(LoG(2, 2, 1.0));

	std::vector<double> var = *kernel_test;
	CORE_INFO(var.size());
	for(int i = 0; i < var.size(); i++) {
		CORE_INFO(var[i]);
	}

	/* CORE_INFO("Result of Laplacian of Gaussien {}", msg); */

	try {
		Magick::Image master(file_path);
		master.type(Magick::GrayscaleType);
		double* a = &var[0];
		master.convolve(3, a); 
		/* master.resize("32x32!"); */
		master.display();
	} catch (std::exception& error_) {
		CORE_ERROR(error_.what());
	}
}

}
