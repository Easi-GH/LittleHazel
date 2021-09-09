#include "lhpch.h"
#include "Application.h"

namespace LH {
	
	//’‚¿Ô≤ª∂Æ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FUNC(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}

		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();
	}

	void Application::OnEvent(Event& event)
	{
		//EventDispatcher dispatcher(event);
		//dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(onWindowClose));
		
		LH_CORE_TRACE("{0}", event);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin())
		{
			(*--it)->OnEvent(event);
			if (event.m_Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}


}