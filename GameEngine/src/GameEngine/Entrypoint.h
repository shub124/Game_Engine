#pragma once
#ifdef HZ_PLATFORM_WINDOWS
#include<stdio.h>
extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc,char** argv)
{
	GameEngine::Log::Init();
	HZ_CORE_WARN("{:<30}", "left aligned");
	HZ_CLIENT_ERROR("{:<30}", "left aligned");
	auto app = GameEngine::CreateApplication();
	app->run();
	delete app;


}

#endif