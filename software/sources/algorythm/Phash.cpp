#include "algorythm/Phash.h"
#include "core/Log.h"
#include "pre-cheader.h"
#include <iostream>
#include <exception>

namespace Hasher {
	void phash(std::string file_path, double sigma) {
		try {
			cv::Mat image = cv::imread(file_path);
			cv::resize(image, image, cv::Size(32, 32), cv::INTER_LINEAR); 
			cv::cvtColor(image, image, cv::COLOR_RGB2GRAY);

			cv::Mat fimage;
			image.convertTo(fimage, CV_32FC1, 1.0/255);

			cv::Mat dimage;
			cv::dct(fimage, dimage);

			vectorToHash(dimage, [](int x) -> int { return x; });

			dimage.convertTo(image, CV_32F); 
			cv::imshow("Result", image);
			cv::waitKey(0);
		} catch(std::exception& error_) {
			CORE_ERROR(error_.what());
		}
	}

	void vectorToHash(cv::Mat& matrix, std::function<int(int)> callback) {
		double sum;
		cv::MatIterator_<int> it, end;
		for(it = matrix.begin<int>(), end = matrix.end<int>(); it != end; it++) {
			sum += callback(*it);
		}

		CORE_INFO(sum);

	}
}
