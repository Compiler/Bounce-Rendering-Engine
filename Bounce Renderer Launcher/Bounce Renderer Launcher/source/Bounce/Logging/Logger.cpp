#include "Logger.h"

#include "spdlog/sinks/basic_file_sink.h" 

namespace bnc {

	std::shared_ptr<spdlog::logger> Logger::_coreLogger;

	void Logger::init() {
		spdlog::set_pattern("%^[%T]%@ %n: %v%$");

		_coreLogger = spdlog::stdout_color_mt("Bounce");
		_coreLogger->set_pattern("%^[%T]%@ %n: %v%$");

		_coreLogger->set_level(spdlog::level::trace);

	}

}