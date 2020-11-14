#pragma once
#include <core/Base.h>
#include <memory>
#include <spdlog/spdlog.h>

namespace Hasher { 
class EXPORT Log { 
    public:
        static void init();
        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return corelogger_; } 
        inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientlogger_; } 
    private:
        static std::shared_ptr<spdlog::logger> corelogger_;
        static std::shared_ptr<spdlog::logger> clientlogger_;
};
}

// Core log macros
#define CORE_ERROR(...) ::Hasher::Log::getCoreLogger()->error(__VA_ARGS__)
#define CORE_WARN(...) ::Hasher::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CORE_INFO(...) ::Hasher::Log::getCoreLogger()->info(__VA_ARGS__)
#define CORE_TRACE(...) ::Hasher::Log::getCoreLogger()->trace(__VA_ARGS__)

// Client log macros                                                                                                 
#define ERROR(...) ::Hasher::Log::getClientLogger()->error(__VA_ARGS__)
#define WARN(...) ::Hasher::Log::getClientLogger()->warn(__VA_ARGS__)
#define INFO(...) ::Hasher::Log::getClientLogger()->info(__VA_ARGS__)
#define TRACE(...) ::Hasher::Log::getClientLogger()->trace(__VA_ARGS__)
