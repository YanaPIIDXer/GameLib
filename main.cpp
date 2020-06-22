#include "GameLib/Application/Application.h"
#include "GameLib/Scene/Scene.h"
#include "GameLib/Object/GameObject.h"
#include "GameLib/Component/TeapotComponent.h"

// ティーポット
class Teapot : public GameObject
{
public:

	Teapot()
	{
		AddComponent(new TeapotComponent());
	}

	virtual ~Teapot()
	{
	}

private:
};

// テストシーン
class TestScene : public Scene
{
public:

	TestScene()
	{
		AddObject(new Teapot());
	}

private:
};

// エントリポイント
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE phInst, LPSTR lpCmd, int nCmd)
{
	Application App(hInst, "GameLib");
	if (!App.Initialize("GameLib", 0, 0, 640, 480, new TestScene()))
	{
		MessageBox(nullptr, "GameLib Init Failed...", "Error", MB_OK);
		return -1;
	}

	App.Run();
	return 0;
}
