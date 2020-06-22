#include "GameLib/Application/Application.h"
#include "GameLib/Scene/Scene.h"
#include "GameLib/Object/GameObject.h"
#include "GameLib/Component/TeapotComponent.h"

// �e�B�[�|�b�g
class Teapot : public GameObject
{
public:

	Teapot()
	{
		AddComponent(new TeapotComponent(this));
	}

	virtual ~Teapot()
	{
	}

private:
};

// �e�X�g�V�[��
class TestScene : public Scene
{
public:

private:
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
