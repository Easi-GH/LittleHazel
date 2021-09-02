#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace LH {

	class LH_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		
		static void Init();
	};
	
}


//Core log macros
#define LH_CORE_TRACE(...)		::LH::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LH_CORE_INFO(...)		::LH::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LH_CORE_WARN(...)		::LH::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LH_CORE_ERROR(...)		::LH::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LH_CORE_CRITICAL(...)	::LH::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define LH_TRACE(...)			::LH::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LH_INFO(...)			::LH::Log::GetClientLogger()->info(__VA_ARGS__)
#define LH_WARN(...)			::LH::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LH_ERROR(...)			::LH::Log::GetClientLogger()->error(__VA_ARGS__)
#define LH_CRITICAL(...)		::LH::Log::GetClientLogger()->critical(__VA_ARGS__)
