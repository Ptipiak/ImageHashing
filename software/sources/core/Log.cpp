#include <core/Log.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Hasher {
	std::shared_ptr<spdlog::logger> Log::corelogger_;
	std::shared_ptr<spdlog::logger> Log::clientlogger_;

	void Log::init() {
		spdlog::set_pattern("%^[%T] %@ %n: %v%$");
		corelogger_ = spdlog::stdout_color_mt("Hasher");
		clientlogger_ = spdlog::stdout_color_mt("Interface");
		corelogger_->set_level(spdlog::level::trace);
		clientlogger_->set_level(spdlog::level::trace);
	}
}
