#include "BounceLauncher.h"
#include <Bounce/Logging/Logger.h>

namespace bnc {

	BounceLauncher::BounceLauncher() {}

	char BounceLauncher::launch() { return this->operator()(); }
	char BounceLauncher::operator()() {
		bnc::BounceCore runner;
		runner.init();
		static float startFrameTime = 0.0f;
		static float elapsedTimePerFrame = 0.0f;
		while (runner._isRunning) {
			startFrameTime = glfwGetTime();
			runner.update();
			runner.render();
			elapsedTimePerFrame = glfwGetTime() - startFrameTime;
			BOUNCE_LOGLVL_LOG("pog {}", elapsedTimePerFrame);
		}
		runner.dispose();
		return 0;
	}

}