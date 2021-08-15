#pragma once

#ifdef LH_PLATFORM_WINDOWS

extern LH::Application* LH::CreatApplication();

int main(int argc, char** argv)
{
	printf("LittleHazel's running\n");
	auto app = LH::CreatApplication();
	app->Run();
	delete app;
}

#endif