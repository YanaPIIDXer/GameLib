#include "GameLib/Application/Application.h"

// エントリポイント
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE phInst, LPSTR lpCmd, int nCmd)
{
	// @TODO:Game派生クラスが無い。
	Application App(nullptr, hInst, "GameLib");
	if (!App.Initialize("GameLib", 0, 0, 640, 480))
	{
		MessageBox(nullptr, "GameLib Init Failed...", "Error", MB_OK);
		return -1;
	}

	App.Run();
	return 0;
}
