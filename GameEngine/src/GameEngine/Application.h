#pragma once
#include "Core.h"
#include"Window.h"
#include"GameEngine/Events/Event.h"
#include"GameEngine/Log.h"
#include"Layer.h"
#include"LayerStack.h"
#include"VertexBuffer.h"
#include"IndexBuffer.h"
#include"Core.h"
namespace GameEngine
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		
	private:
		std::unique_ptr<Window>m_Window;
		std::unique_ptr<VertexBuffer>m_VertexBuffer;
		std::unique_ptr<IndexBuffer>m_IndexBuffer;
		bool m_Running=true;
		bool OnWindowClose(Event&);
		LayerStack m_LayerStack;
		unsigned int m_VertexArray;
		
		

	};
	Application* CreateApplication();
}

