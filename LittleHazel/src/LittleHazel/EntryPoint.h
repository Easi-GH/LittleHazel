#pragma once

#ifdef LH_PLATFORM_WINDOWS

extern LH::Application* LH::CreatApplication();

int main(int argc, char** argv)
{
	printf("LittleHazel's running\n");
	
	LH::Log::Init();
	LH::Log::GetCoreLogger()->warn("Initialize Log");
	LH::Log::GetClientLogger()->info("Initialize Log, too");

	auto app = LH::CreatApplication();
	app->Run();
	delete app;
}

#endif