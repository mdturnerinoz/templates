#include <cstdio>

#define PLATFORM_WINDOWS	1
#define PLATFORM_LINUX		2
#define PLATFORM_MACOS		3
#define PLATFORM_ANDROID	4
#define PLATFORM_IOS		   5

#if defined(_WIN32)
 #define PLATFORM_ID		PLATFORM_WINDOWS
 #define PLATFORM_NAME "Windows"
#elif defined(__ANDROID__)		// must come before __linux__ as Android also #defines __linux__
 #define PLATFORM_ID		PLATFORM_ANDROID
 #define PLATFORM_NAME "Android"
#elif defined(__linux__)
 #define PLATFORM_ID		PLATFORM_LINUX
 #define PLATFORM_NAME  "Linux"
#elif defined(__MACH__)
 #include <TargetConditionals.h>
 #if (TARGET_OS_IPHONE == 1)
  #define PLATFORM_ID		PLATFORM_IOS
  #define PLATFORM_NAME    "iOS"
 #else
  #define PLATFORM_ID		PLATFORM_MACOS
  #define PLATFORM_NAME    "Mac OS X"
 #endif
#endif

namespace Private
{
	// generic declaration (the base interface class)
 	template <int PlatformID>
	class Debug
	{
	public:
		static void print(const char *str);
	};
	// specialization for Windows platform (the derived class for Windows)
	template<>
	class Debug<PLATFORM_WINDOWS>
	{
	public:
		static void print(const char *str);
	};
	// specialization for Android platform (the derived class for Android)
	template<>
	class Debug<PLATFORM_ANDROID>
	{
	public:
		static void print(const char *str);
	};
	// generic platform (base interface class) implementation
	template <int PlatformID>
	void Debug<PlatformID>::print(const char *str)
	{
		::puts(str);
	}
}

typedef Private::Debug<PLATFORM_ID>	Debug;

#if (PLATFORM_ID == PLATFORM_WINDOWS)
#include <windows.h>
// implementation for Windows
void Debug::print(const char *str)
{
	::OutputDebugStringA(str);
	::OutputDebugStringA("\n");
}
#elif (PLATFORM_ID == PLATFORM_ANDROID)
#include <android/log.h>
// implementation for Android
void Debug::print(const char *str)
{
	::__android_log_print(ANDROID_LOG_INFO, "MyApp", str);
}
#endif
