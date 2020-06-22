#include "GameLib/Application/Application.h"
#include "GameLib/Scene/Scene.h"

// �e�X�g�V�[��
class TestScene : public Scene
{
};


// �G���g���|�C���g
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE phInst, LPSTR lpCmd, int nCmd)
{
	Application App(hInst, "GameLib", new TestScene());
	if (!App.Initialize("GameLib", 0, 0, 640, 480))
	{
		MessageBox(nullptr, "GameLib Init Failed...", "Error", MB_OK);
		return -1;
	}

	App.Run();
	return 0;
}
