#include "algorythm/Phash.h"
#include "core/Log.h"
#include "pre-cheader.h"
#include <exception>

namespace Hasher {

void phash(std::string file_path) {

	/* double kernel_[7] [7] = { */
	/* 	{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, */
	/* 	{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, */
	/* 	{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, */
	/* 	{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, */
	/* 	{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, */
	/* 	{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, */
	/* 	{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0} */
	/* }; */

	double kernel_[] = {
		 0.0,  1.0,  0.0,
		 1.0, -4.0,  1.0,
		 0.0,  1.0,  0.0
	};

	try {
		Magick::Image master(file_path);
		master.type(Magick::GrayscaleType);
		master.convolve(3, kernel_); 
		master.resize("32x32!");
		master.display();
	} catch (std::exception& error_) {
		CORE_ERROR(error_.what());
	}
}

}
