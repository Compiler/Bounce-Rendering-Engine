#pragma once
#include <Bounce/Bounce.h>
#define SPDLOG_TRACE_ON
#include <spdlog/spdlog.h>
#include <spdlog/sinks/sink.h>
#include "spdlog/sinks/ostream_sink.h" 
#include "spdlog/sinks/stdout_color_sinks.h"



namespace bnc {
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
	class BOUNCE_API Logger {
	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;
	public:
		Logger() = delete;
		Logger(const Logger&) = delete;
		static void init();
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return _coreLogger; };
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return _clientLogger; };
	};
}





#ifdef _DEBUG

#define BOUNCE_CORE_TRACE(...) ::bnc::Logger::getCoreLogger()->trace(__VA_ARGS__)
#define BOUNCE_CORE_DEBUG(...) ::bnc::Logger::getCoreLogger()->debug(__VA_ARGS__)
#define BOUNCE_CORE_LOG(...) ::bnc::Logger::getCoreLogger()->info(__VA_ARGS__)
#define BOUNCE_CORE_WARN(...) ::bnc::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define BOUNCE_CORE_ERROR(...) ::bnc::Logger::getCoreLogger()->error(__VA_ARGS__)
#define BOUNCE_CORE_FATAL(...) {::bnc::Logger::getCoreLogger()->critical(__VA_ARGS__); DebugBreak();}

#else 
#define BOUNCE_CORE_TRACE(...)
#define BOUNCE_CORE_DEBUG(...)
#define BOUNCE_CORE_LOG(...) 
#define BOUNCE_CORE_WARN(...)
#define BOUNCE_CORE_ERROR(...) 
#define BOUNCE_CORE_FATAL(...) 

#endif

#define BOUNCE_TRACE(...) ::bnc::Logger::getClientLogger()->trace(__VA_ARGS__)
#define BOUNCE_DEBUG(...) ::bnc::Logger::getClientLogger()->debug(__VA_ARGS__)
#define BOUNCE_LOG(...) ::bnc::Logger::getClientLogger()->info(__VA_ARGS__)
#define BOUNCE_WARN(...) ::bnc::Logger::getClientLogger()->warn(__VA_ARGS__)
#define BOUNCE_ERROR(...) ::bnc::Logger::getClientLogger()->error(__VA_ARGS__)
#define BOUNCE_FATAL(...) ::bnc::Logger::getClientLogger()->critical(__VA_ARGS__)