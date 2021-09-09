#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace LH {

	class LH_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	};

	//To be defined in CLIENT
	Application* CreatApplication();

}
