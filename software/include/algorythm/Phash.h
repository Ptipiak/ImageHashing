#pragma once
#include "core/Base.h"
#include "pre-cheader.h"

namespace Hasher {

	EXPORT void phash(std::string file_path, double sigma);
	void vectorToHash(cv::Mat& matrix, std::function<int(int)> callback);

}
