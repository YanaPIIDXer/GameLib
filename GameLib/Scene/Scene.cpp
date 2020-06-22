#include "Scene.h"
#include "../Application/Application.h"
#include "../D3DX/Modules/D3DXRender.h"
#include "../Object/GameObject.h"

// コンストラクタ
Scene::Scene()
	: pApplication(nullptr)
{
}

// デストラクタ
Scene::~Scene()
{
}

// 初期化
void Scene::Initialize(Application *pInApplication)
{
	pApplication = pInApplication;
}

// オブジェクト追加
void Scene::AddObject(GameObject *pObject)
{
	pObject->Initialize(this);
	Objects.push_back(ObjectPtr(pObject));
}

// 毎フレームの処理
void Scene::Poll()
{
	for (auto It = Objects.begin(); It != Objects.end(); ++It)
	{
		if ((*It)->IsDestroyed())
		{
			It = Objects.erase(It);
		}
	}

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
