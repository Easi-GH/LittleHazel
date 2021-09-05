#pragma once

#include "LittleHazel/Window.h"
#include <GLFW/glfw3.h>

namespace LH {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.windowWidth; }
		inline unsigned int GetHeight() const override { return m_Data.windowHeight; }
		
		//Window attributes
		void SetEventCallBack(const EventCallBackFunc& callback) { m_Data.EventCallBack = callback; }
		void SetVSync(bool enabled) override;
		bool IsVsync() const override;

	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string windowTitle;
			unsigned int windowWidth, windowHeight;
			bool VSyncStatus;

			EventCallBackFunc EventCallBack;
		};

		WindowData m_Data;
	};

}