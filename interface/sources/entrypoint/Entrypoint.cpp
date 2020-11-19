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
	Hasher::phash(argv[1]);
}
