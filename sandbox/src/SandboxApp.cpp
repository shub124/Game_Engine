#include"GameEngine.h"
class SandboxApp:public GameEngine :: Application
{
public:
	SandboxApp()
	{

	}

	~SandboxApp()
	{

	}


};

GameEngine::Application* GameEngine::CreateApplication()
{
	return new SandboxApp();

}
