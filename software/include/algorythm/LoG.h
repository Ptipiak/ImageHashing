#pragma once
#include "pre-cheader.h"
#include "core/Log.h"
namespace  Hasher {

	std::unique_ptr<std::vector<double>> LoG(int width, int heigt, double sigma);
	std::unique_ptr<std::vector<double>> transpose(std::vector<double> matrix, int row_size);

}
