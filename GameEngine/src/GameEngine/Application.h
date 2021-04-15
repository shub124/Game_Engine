#pragma once
#include "Core.h"
#include"Window.h"
#include"GameEngine/Events/Event.h"
#include"GameEngine/Log.h"
namespace GameEngine
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
		void OnEvent(Event&);
		
	private:
		std::unique_ptr<Window>m_Window;
		bool m_Running=true;
		bool OnWindowClose(Event&);
		
		

	};
	Application* CreateApplication();
}

