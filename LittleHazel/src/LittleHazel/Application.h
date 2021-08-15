#pragma once

#include "Core.h"

namespace LH {

	class LH_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreatApplication();

}
