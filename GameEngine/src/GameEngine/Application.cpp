#include "Application.h"
#include"GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Log.h"
#include<GLFW/glfw3.h>
namespace GameEngine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->setEventCallback(std::bind(&Application::OnEvent,this,std::placeholders::_1));

	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		HZ_CORE_INFO("{0}",e);
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			
		}
	}

	bool Application::OnWindowClose(Event& e)
	{
		m_Running = false;
		return true;
	}
	void Application::run()
	{
		WindowResizeEvent e(120, 80);
		HZ_CLIENT_TRACE(e);
		
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			m_Window->OnUpdate();

		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);

	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);

	}
}
