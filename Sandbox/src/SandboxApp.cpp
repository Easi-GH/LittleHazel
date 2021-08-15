#include <iostream>
#include <LittleHazel.h>

class Sandbox : public LH::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

LH::Application* LH::CreatApplication()
{
	return new Sandbox();
}