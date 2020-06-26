#include "GameObject.h"
#include "../Scene/Scene.h"

// コンストラクタ
GameObject::GameObject()
	: pScene(nullptr)
	, bIsDestroyed(false)
{
}

// デストラクタ
GameObject::~GameObject()
{
}

// 初期化
void GameObject::Initialize(Scene *pInScene)
{
	pScene = pInScene;
	for (auto pCmp : Components)
	{
		if (!pCmp->IsInitialized())
		{
			pCmp->Initialize(this, pScene->GetComponentInitializer());
		}
	}
}

// コンポーネント追加
void GameObject::AddComponent(ObjectComponent *pComponent)
{
	Components.push_back(ComponentPtr(pComponent));
	if (pScene != nullptr)
	{
		pComponent->Initialize(this, pScene->GetComponentInitializer());
	}
}

// オブジェクトの破棄
void GameObject::Destroy()
{
	if (bIsDestroyed) { return; }

	OnDestroy();
	bIsDestroyed = true;
}

// 更新
void GameObject::UpdateObject(float DeltaTime)
{
	for (auto Cmp : Components)
	{
		Cmp->Update(DeltaTime);
	}

	Update(DeltaTime);
}

// 描画
void GameObject::Render(D3DXRender *pRender)
{
	for (auto pCmp : Components)
	{
		if (pCmp->IsRenderComponent())
		{
			pCmp->Render(pRender);
		}
	}
}


// 移動
void GameObject::Move(float X, float Y, float Z)
{
	Trans.Move(X, Y, Z);
}

// ワールド軸を基準とした移動
void GameObject::MoveWorld(float X, float Y, float Z)
{
	Trans.MoveWorld(X, Y, Z);
}

// 回転
void GameObject::Rotate(float Yaw, float Pitch, float Roll)
{
	Trans.Rotate(Yaw, Pitch, Roll);
}
