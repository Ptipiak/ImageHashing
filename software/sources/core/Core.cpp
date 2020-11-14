#include "spdlog/spdlog.h"
#include "core/Base.h"
#include "core/Core.h"
#include "core/Log.h"

using namespace Hasher;

void Core::init() {
}

int Core::run() {
	running_ = true;
	return 0;
}
