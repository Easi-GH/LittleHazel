#include "lhpch.h"
#include "Application.h"

namespace LH {
	
	LH::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	LH::Application::~Application()
	{
	}

	void LH::Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

}