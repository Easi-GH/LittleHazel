#pragma once

#include "Core.h"
#include "Window.h"

namespace LH {

	class LH_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	//To be defined in CLIENT
	Application* CreatApplication();

}
