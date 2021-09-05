#pragma once

#include "lhpch.h"
#include "LittleHazel/Core.h"
#include "LittleHazel/Events/Event.h"

namespace LH {

	struct WindowProperties
	{
		std::string windowTitle;
		unsigned int windowWidth, windowHeight;

		WindowProperties(const std::string title = "Little Hazel",
			unsigned int width = 1280,
			unsigned int height = 720)
			: windowTitle(title), windowWidth(width), windowHeight(height)
		{
		}
	};

	//Interface
	class LH_API Window
	{
	public:
		using EventCallBackFunc = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallBack(const EventCallBackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVsync() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};

}