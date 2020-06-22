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

// オブジェクトの破棄
void GameObject::Destroy()
{
	if (bIsDestroyed) { return; }

	OnDestroy();
	bIsDestroyed = true;
}
