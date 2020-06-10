#pragma once

#ifdef BOUNCE_ENGINE
	#define BOUNCE_API __declspec(dllexport)
#else 
	#define BOUNCE_API __declspec(dllimport)
#endif