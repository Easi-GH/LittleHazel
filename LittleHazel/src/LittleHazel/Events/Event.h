#pragma once

#include "LittleHazel/Core.h"


namespace LH {

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		Apptick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	
	enum EventCatagory
	{
		None = 0,
		EventCatagoryApplication	= BIT(0),
		EventCatagoryInput			= BIT(1),
		EventCatagoryKeyboard		= BIT(2),
		EventCatagoryMouse			= BIT(3),
		EventCatagoryMouseButton	= BIT(4)
	};

	class LH_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCatagoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }
		

	};
}