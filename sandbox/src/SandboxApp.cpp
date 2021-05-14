#include"GameEngine.h"


class ExampleLayer :public GameEngine::Layer
{
public:
	ExampleLayer() 
		
	{
		
	}

	void OnUpdate() override
	{
		HZ_CLIENT_INFO("ExampleLayer::Update");
	}

	void OnEvent(GameEngine::Event& e) override
	{
		HZ_CLIENT_TRACE("{0}", e);
	}

	~ExampleLayer()
	{

	}

};

class SandboxApp:public GameEngine :: Application
{
public:
	SandboxApp()
	{
		PushLayer(new ExampleLayer());
	}

	~SandboxApp()
	{

	}


};

GameEngine::Application* GameEngine::CreateApplication()
{
	return new SandboxApp();

}
