#pragma once

#include <GameEngine/Events/Event.h>
#include<sstream>
namespace GameEngine
{
	class HAZEL_API WindowResizeEvent: public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_width(width),m_height(height)
		{

		}

		unsigned int getWidth()
		{
			return m_width;
		}

		unsigned int getHeight()
		{
			return m_height;
		}

		std::string ToString() const override {

			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_width;
		unsigned int m_height;


	};

	class HAZEL_API  WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
			EVENT_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CATEGORY(EventCategoryApplication)
	};

	class HAZEL_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CATEGORY(EventCategoryApplication)
	};

}