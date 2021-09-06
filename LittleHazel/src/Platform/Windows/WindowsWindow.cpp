#include "lhpch.h"
#include "WindowsWindow.h"
#include "LittleHazel/Events/ApplicationEvent.h"
#include "LittleHazel/Events/KeyEvent.h"
#include "LittleHazel/Events/MouseEvent.h"

namespace LH {

	static bool s_GLFWInitialized = false;

	static void glfwErrorCallback(int errorCode, const char* description)
	{
		LH_CORE_ERROR("GLFW error ({0}): {1}", errorCode, description);
	}

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
			//TODO: glfwterminate on system shutdown
			int status = glfwInit();
			LH_CORE_ASSERT(status, "Could not initialize GLFW.");
			glfwSetErrorCallback(glfwErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(props.windowWidth, props.windowHeight, props.windowTitle.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		//Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				data.windowWidth = width;
				data.windowHeight = height;

				WindowResizeEvent event(width, height);
				data.EventCallBack(event);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				data.EventCallBack(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.EventCallBack(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallBack(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						data.EventCallBack(event);
						break;
					}
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.EventCallBack(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.EventCallBack(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double OffsetX, double OffsetY)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)OffsetX, (float)OffsetY);
				data.EventCallBack(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double PosX, double PosY)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)PosX, (float)PosY);
				data.EventCallBack(event);
			});
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