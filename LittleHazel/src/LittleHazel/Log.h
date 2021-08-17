#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

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

#define LH_CORE_ERROR(...) ::LH::Log::GetCoreLogger()->error(__VA_ARGS__)
