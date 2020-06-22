#include "GameLib/Application/Application.h"
#include "GameLib/Game/GameBase.h"

// ゲームクラス
class Game : public GameBase
{
public:
};

// エントリポイント
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE phInst, LPSTR lpCmd, int nCmd)
{
	Game MyGame;
	Application App(&MyGame, hInst, "GameLib");
	if (!App.Initialize("GameLib", 0, 0, 640, 480))
	{
		MessageBox(nullptr, "GameLib Init Failed...", "Error", MB_OK);
		return -1;
	}

	App.Run();
	return 0;
}
