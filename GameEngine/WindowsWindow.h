#pragma once
#include"GLFW/glfw3.h"
#include"GameEngine/Window.h"
#include"GameEngine/Events/ApplicationEvent.h"
#include"GameEngine/Events/MouseEvent.h"
#include"GameEngine/Events/KeyboardEvent.h"

namespace GameEngine {
	class HAZEL_API WindowsWindow:public Window
	{
	public:
		WindowsWindow(const Windowprops& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		inline  int get_Width()  override { return m_Data.width; }
		inline int get_Height() override { return m_Data.height; }
		inline void setEventCallback(const EventCallbackFn& callback) {  m_Data.EventCallback = callback; }
		void  setVsync(bool enabled) override;
		bool IsVsync() const override;
	private:
		virtual void Init(const Windowprops& props);
		virtual void ShutDown();

		GLFWwindow* m_Window;
		struct WindowData
		{
			std::string title;
			int width, height;
			bool vSync;

			EventCallbackFn EventCallback;
		};
		WindowData m_Data;







	};

}


