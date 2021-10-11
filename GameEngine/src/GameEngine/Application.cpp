#include "Application.h"
#include"GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Log.h"
#include<GLFW/glfw3.h>
#include<glad/glad.h>
#include"Renderer.h"


namespace GameEngine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->setEventCallback(std::bind(&Application::OnEvent,this,std::placeholders::_1));

		//Vertex Array
		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);
		float vertices[3 * 3] = {
			-0.5f, 0.5f, 0.0f,
			0.5f, -0.5f,0.0f,
			0.0f, 0.5f, 0.5f

		};
		
		
		Renderer r;
		//r.setRendererAPI(Renderer_API::OpenGL);

		//VertexBuffer
		m_VertexBuffer.reset(VertexBuffer::Create(vertices,sizeof(vertices)));


		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);


		//IndexBuffer
		int indices[3] = { 0,1,2 };
		m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices), 3));

		

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
			glClearColor(0,0,0,0);
			glClear(GL_COLOR_BUFFER_BIT);

			//glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

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
