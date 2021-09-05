#include "lhpch.h"
#include "WindowsWindow.h"

namespace LH {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProperties& props)
	{
		m_Data.windowTitle = props.windowTitle;
		m_Data.windowWidth = props.windowWidth;
		m_Data.windowHeight = props.windowHeight;

		LH_CORE_INFO("Creating window {0} ({1}, {2})", props.windowTitle, props.windowWidth, props.windowHeight);

		if (!s_GLFWInitialized)
		{
			int status = glfwInit();
			LH_CORE_ASSERT(status, "Could not initialize GLFW.");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(props.windowWidth, props.windowHeight, props.windowTitle.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSyncStatus = enabled;
	}

	bool WindowsWindow::IsVsync() const
	{
		return m_Data.VSyncStatus;
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}