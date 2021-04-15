#pragma once
#include"GameEngine/Core.h"
#include"GameEngine/Events/Event.h"
namespace GameEngine {

	struct Windowprops
	{
		std::string m_title;
		int m_width;
		int m_height;
		Windowprops(const std::string & title="GameEngine",int width=1600,int height=900)
			:m_width(width),m_height(height),m_title(title)
		{

		}

	};
	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() = default;
		virtual void OnUpdate() = 0;
		virtual int get_Width() = 0;
		virtual int get_Height() = 0;

		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVsync(bool enabled) = 0;
		virtual bool IsVsync( ) const= 0;
		static Window* Create(const Windowprops& props = Windowprops());
		


	};
}