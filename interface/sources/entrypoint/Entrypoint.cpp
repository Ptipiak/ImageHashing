#include <Hasher.h>
#include <iostream>

class Interface : public Hasher::Application {
	public:
		Interface() {}
		~Interface() {}
};

Hasher::Application* Hasher::CreateApplication()
{
	return new Interface;
};

int main(int argc, char** argv) {
	// Parse the arguments, migh be improve by using a dedicated function 
	// and a bunch of config files
	std::string filepath;
	double sigma = 1.4;
	CLI::App app{"App description"};
	app.add_option<std::string>("filepath", filepath, "The input image to hash")
	->required();
	app.add_option<double>("-s,--sigma", sigma, "The sigma used for the LoG convolution")
	->check(CLI::PositiveNumber);
	CLI11_PARSE(app, argc, argv);

	// Init the logger
	Hasher::Log::init();
	Hasher::phash(filepath, sigma);
	return 0;
}
