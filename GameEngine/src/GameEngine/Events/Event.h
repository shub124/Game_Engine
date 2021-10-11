
#pragma once

#include<functional>
#include "GameEngine/Core.h"
#include<string>
#include<sstream>


namespace GameEngine
{
	enum class EventType {
		None = 0,
		WindowClose,WindowResize,WindowFocus,WindowLostFocus, WindowMoved,
		AppTick,AppUpdate,AppRender,
		KeyPressed,KeyReleased,
		MouseButton,MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled

	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryMouse = BIT(1),
		EventCategoryInput= BIT(2),
		EventCategoryKeyboard= BIT(3),
		EventCategoryMouseButton =BIT(4)

	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type;}\
								virtual EventType GetEventType() const override {return GetStaticType();}\
								virtual const char* GetName() const override {return #type;}

#define EVENT_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const  { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_handled = false;


	};

	class EventDispatcher {
		
	public:
		EventDispatcher(Event& event)
			:m_event(event)
		{
			
		}

		template<typename T, typename F>
		bool dispatch(const F& func)
		{
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.m_handled |= func(static_cast<T&>(m_event));
				return true;

			}
			return false;
		}

	private:
		Event& m_event;

	};

	inline std::ostream& operator<<(std::ostream& os,  const Event& e)
	{
		return os << e.ToString();
	}

}
