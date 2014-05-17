#include "CSystem.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	Application::CSystem* pSystem = new Application::CSystem;

	if(pSystem->Initialise())
		pSystem->Run();

	pSystem->Shutdown();

	delete pSystem;
	pSystem = 0;

	return 0;
}