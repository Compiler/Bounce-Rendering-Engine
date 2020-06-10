#pragma once
#include <Bounce/Bounce.h>
#include <Bounce/Core/BounceCore.h>

namespace bnc {


	class BOUNCE_API BounceLauncher {

	public:
		BounceLauncher();
		char launch();
		char operator () ();
	};

}