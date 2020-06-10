#include "Logger.h"

namespace bnc {


	std::shared_ptr<spdlog::logger> Logger::_coreLogger;
	std::shared_ptr<spdlog::logger> Logger::_clientLogger;

	void Logger::init() {
		spdlog::set_pattern("%^[%T]%@ %n: %v%$");


		_coreLogger = spdlog::stdout_color_mt("Bounce");
		_coreLogger->set_pattern("%^[%T]%@ %n: %v%$");

		_coreLogger->set_level(spdlog::level::trace);

		_clientLogger = spdlog::stdout_color_mt("Launcher");
		_coreLogger->set_level(spdlog::level::trace);


	}




}