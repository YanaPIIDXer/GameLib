#include "GameLib/Application/Application.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE phInst, LPSTR lpCmd, int nCmd)
{
	Application App(hInst, "GameLib", "GameLib", 0, 0, 640, 480);
	App.Run();
	return 0;
}
