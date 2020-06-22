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
