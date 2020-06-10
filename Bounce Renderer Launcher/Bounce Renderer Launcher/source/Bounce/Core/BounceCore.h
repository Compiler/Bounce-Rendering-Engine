#pragma once
#include <Bounce/Bounce.h>
#include <GLFW/glfw3.h>
#include <Bounce/Logging/Logger.h>

namespace bnc {


	class BOUNCE_API BounceCore {
		friend class BounceLauncher;
	private:
		bool _isRunning = true;
		double _fps = 0.0;

	public:
		BounceCore();
		void init();
		void update();
		void render();
		void dispose();


	};

}