#pragma once
#include <Bounce/Bounce.h>
#include <Bounce/Core/BounceCore.h>

namespace bnc {


	class BOUNCE_API BounceLauncher {

	public:
		BounceLauncher() {}
		void operator () () {
			bnc::BounceCore runner;
			runner.init();
			
			while (runner._isRunning) {
				runner.update();
				runner.render();
			}
		}
	};

}