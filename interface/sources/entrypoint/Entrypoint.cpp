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
	Hasher::Log::init();
	std::cout << "Welcome to the interface\n";
	INFO("Welcome to spdlog.");
	WARN("This is a warning from spdlog.");
}
