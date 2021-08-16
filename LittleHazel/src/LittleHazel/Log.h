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
		std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};

}
