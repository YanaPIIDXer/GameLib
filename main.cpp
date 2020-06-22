#include "GameLib/Application/Application.h"
#include "GameLib/Game/GameBase.h"

// �Q�[���N���X
class Game : public GameBase
{
public:
};

// �G���g���|�C���g
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
