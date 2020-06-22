#include "Scene.h"
#include "../Application/Application.h"

// コンストラクタ
Scene::Scene()
	: pApplication(nullptr)
{
}

// デストラクタ
Scene::~Scene()
{
}

// 毎フレームの処理
void Scene::Poll()
{
	Render();
}

// 次のシーンに遷移
void Scene::SetNextScene(Scene *pNextScene)
{
	pApplication->SetNextScene(pNextScene);
}


// 描画
void Scene::Render()
{
	
}
