#pragma once

#ifdef LH_PLATFORM_WINDOWS
	#ifdef LH_BUILD_DLL
		#define LH_API __declspec(dllexport)
	#else
		#define LH_API __declspec(dllimport)
	#endif
#else
	#error LittleHazel now only supports Windows.
#endif

#ifdef LH_ASSERTS_ENABLE
	#define LH_CORE_ASSERT(x, ...) { if(!x) { LH_CORE_ERROE("Assertion failed: {0}", __VA_AEGS__); __debugbreak(); } }
	#define LH_ASSERT(x, ...) { if(!x) { LH_ERROE("Assertion failed: {0}", __VA_AEGS__); __debugbreak(); } }
#else
	#define LH_CORE_ASSERT(x, ...)
	#define LH_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)