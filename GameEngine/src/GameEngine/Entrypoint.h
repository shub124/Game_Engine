#pragma once
#ifdef HZ_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc,char** argv)
{
	auto app = GameEngine::CreateApplication();
	app->run();
	delete app;


}

#endif