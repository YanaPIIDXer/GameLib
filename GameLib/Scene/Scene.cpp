#include "Scene.h"
#include "../Application/Application.h"
#include "../D3DX/Modules/D3DXRender.h"
#include "../Object/GameObject.h"
#pragma comment(lib, "winmm.lib")

// コンストラクタ
Scene::Scene()
	: pApplication(nullptr)
{
	PrevTime = timeGetTime();
}

// デストラクタ
Scene::~Scene()
{
}

// 初期化
void Scene::Initialize(Application *pInApplication)
{
	pApplication = pInApplication;
	CmpInitializer.pD3DXDevices = pApplication->GetD3DXDevices();
	for (auto pObj : Objects)
	{
		if (!pObj->IsInitialized())
		{
			pObj->Initialize(this);
		}
	}
}

// オブジェクト追加
void Scene::AddObject(GameObject *pObject)
{
	Objects.push_back(ObjectPtr(pObject));
	if (pApplication != nullptr)
	{
		pObject->Initialize(this);
	}
}

// 毎フレームの処理
void Scene::Poll()
{
	DWORD CurrentTime = timeGetTime();
	float DeltaTime = (CurrentTime - PrevTime) * 0.001f;
	for (auto It = Objects.begin(); It != Objects.end(); ++It)
	{
		if ((*It)->IsDestroyed())
		{
			It = Objects.erase(It);
		}
		else
		{
			(*It)->UpdateObject(DeltaTime);
		}
	}

	PrevTime = CurrentTime;

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

	// ======== 仮 =========
	D3DXVECTOR3 Eye(0.0f, 3.0f, -5.0f);
	D3DXVECTOR3 LookAt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Up(0.0f, 1.0f, 0.0f);

	D3DXMATRIX ViewMat;
	D3DXMatrixLookAtLH(&ViewMat, &Eye, &LookAt, &Up);
	// ゴリ押しだけど仮なので許せ。
	pApplication->GetD3DXDevices().lock()->pDevice->SetTransform(D3DTS_VIEW, &ViewMat);

	D3DXMATRIX ProjMat;
	D3DXMatrixPerspectiveFovLH(&ProjMat, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	pApplication->GetD3DXDevices().lock()->pDevice->SetTransform(D3DTS_PROJECTION, &ProjMat);
	// =====================

	for (auto It = Objects.begin(); It != Objects.end(); ++It)
	{
		(*It)->Render(pRender);
	}

	pRender->End();
}
