#include "GameObject.h"

// コンストラクタ
GameObject::GameObject()
	: bIsDestroyed(false)
{
}

// デストラクタ
GameObject::~GameObject()
{
}

// コンポーネント追加
void GameObject::AddComponent(ObjectComponent *pComponent)
{
	pComponent->SetParent(this);
	Components.push_back(ComponentPtr(pComponent));
}

// オブジェクトの破棄
void GameObject::Destroy()
{
	if (bIsDestroyed) { return; }

	OnDestroy();
	bIsDestroyed = true;
}
