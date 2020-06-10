#include "BounceLauncher.h"

namespace bnc {

	BounceLauncher::BounceLauncher() {}
	char BounceLauncher::operator()() {
		bnc::BounceCore runner;
		runner.init();

		while (runner._isRunning) {
			runner.update();
			runner.render();
		}
		runner.dispose();
		return 0;
	}

}