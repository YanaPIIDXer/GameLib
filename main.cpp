#include "GameLib/Application/Application.h"

// �G���g���|�C���g
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE phInst, LPSTR lpCmd, int nCmd)
{
	// @TODO:Game�h���N���X�������B
	Application App(nullptr, hInst, "GameLib");
	if (!App.Initialize("GameLib", 0, 0, 640, 480))
	{
		MessageBox(nullptr, "GameLib Init Failed...", "Error", MB_OK);
		return -1;
	}

	App.Run();
	return 0;
}
