#pragma once

#ifdef LH_PLATFORM_WINDOWS

extern LH::Application* LH::CreatApplication();

int main(int argc, char** argv)
{
	printf("LittleHazel's running\n");

	LH::Log::Init();
	LH_CORE_TRACE("Initialize Log");
	int a = 5;
	LH_TRACE("Initialize Log, too. And Var = {0}", a);

	auto app = LH::CreatApplication();
	app->Run();
	delete app;
}

#endif

