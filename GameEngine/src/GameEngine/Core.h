#pragma once
enum class  Renderer_API {
	None = 0, OpenGL = 1
};
#define WINDOWS_MODE 0
#define CROSS_PLATFORM 1
#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif


#define BIT(x) (1<<x)
#ifdef HZ_ENABLE_ASSERTS
	#define HZ_CLIENT_ASSERT(x,...) {if(!(x)) {HZ_CLIENT_ERROR("ASSERTION FAILED: {0}",__VA_ARGS__);__debugbreak();}}
	#define HZ_CORE_ASSERT(x,...) {if(!(x)) {HZ_CORE_ERROR("ASSERTION FAILED: {0}",__VA_ARGS__);__debugbreak();}}
#else
	#define HZ_CLIENT_ASSERT(x,...)
	#define HZ_CORE_ASSERT(x,...) 
#endif // HZ_ENABLE_ASSETS
