#include "Scene.h"
#include "../Application/Application.h"
#include "../D3DX/Modules/D3DXRender.h"

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
	auto *pRender = pApplication->GetD3DXModule<D3DXRender>("Render");
	pRender->Begin();

	pRender->End();
}
