#pragma once

#include <string>
#include <functional>

#ifdef LH_PLATFORM_WINDOWS
	#ifdef LH_BUILD_DLL
		#define LH_API __declspec(dllexport)
	#else
		#define LH_API __declspec(dllimport)
	#endif
#else
	#error LittleHazel now only supports Windows.
#endif

#define BIT(x) (1 << x)