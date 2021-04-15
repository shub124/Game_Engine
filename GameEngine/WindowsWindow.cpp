#include "WindowsWindow.h"
#include "GameEngine/Log.h"

namespace GameEngine
{
	bool s_GLFWInitialized = false;
	Window*  Window::Create(const Windowprops& props)
	{
		return new WindowsWindow(props);

	}

	WindowsWindow::WindowsWindow(const Windowprops& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		ShutDown();

	}

	void WindowsWindow::Init(const Windowprops& props)
	{
		m_Data.title = props.m_title;
		m_Data.width = props.m_width;
		m_Data.height = props.m_height;

		HZ_CORE_INFO("creating window {0} ({1} ,{2}) ", props.m_title, props.m_height, props.m_width);
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			HZ_CORE_ASSERT(success, "Could not Initialize GLFW");
			s_GLFWInitialized = true;
			
		}
		m_Window = glfwCreateWindow(props.m_width, props.m_height, props.m_title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVsync(true);

		//Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window,int width,int height)
			{
				WindowData & data=*(WindowData*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;
				WindowResizeEvent e(width, height);
				data.EventCallback(e);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent e;
				data.EventCallback(e);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window,int key,int scancode,int action,int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent e(key, 0);
						data.EventCallback(e);
						break;

					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent e(key);
						data.EventCallback(e);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent e(key, 1);
						data.EventCallback(e);
						break;

					}

				}

			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window,int button,int action,int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent e(button);
						data.EventCallback(e);

					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent e(button);
						data.EventCallback(e);
					}

				}


			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double X,double Y)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent e((float)X, (float)Y);
				data.EventCallback(e);


			});

		glfwSetCursorPosCallback(m_Window,[](GLFWwindow* window, double X, double Y)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent e((float)X, (float)Y);
				data.EventCallback(e);


			});



	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);

	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
	void WindowsWindow::setVsync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
		m_Data.vSync = true;
	}
	bool WindowsWindow::IsVsync() const
	{
		return m_Data.vSync;
	}

}
