#pragma once
#include <GameEngine/Events/Event.h>
#include<sstream>
#include<string>
namespace GameEngine
{
	class  HAZEL_API KeyEvent :public Event
	{
	public:
		int GetKeyCode() { return m_KeyCode; }
		EVENT_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		int m_KeyCode;
		KeyEvent(const int keycode)
		{
			m_KeyCode = keycode;
		}

	};

	class HAZEL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int keycode, const int repeatCount)
			:KeyEvent(keycode), m_RepeatCount(repeatCount)
		{

		}

		int getRepeeatCount() const { return m_RepeatCount; }

		std::string ToString() const  override
		{
			std::stringstream ss;
			ss<<"KeyPressedEvent: "<< m_KeyCode<< " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};


	class HAZEL_API KeyReleasedEvent: public KeyEvent
	{
	public:

		KeyReleasedEvent(const int keycode)
			:KeyEvent(keycode)
		{

		}
		std::string ToString() const  override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)

	};
}