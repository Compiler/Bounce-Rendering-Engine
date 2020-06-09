#pragma once

int test = 4444;

#ifdef BOUNCE_ENGINE
	#define BOUNCE_API __declspec(dllexport)
#else 
	#define BOUNCE_API __declspec(dllimport)
#endif