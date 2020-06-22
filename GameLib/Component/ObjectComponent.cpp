#include "ObjectComponent.h"

// コンストラクタ
ObjectComponent::ObjectComponent()
{
}

// デストラクタ
ObjectComponent::~ObjectComponent()
{
}

// 初期化
void ObjectComponent::Initialize(GameObject *pInParent)
{
	pParent = pInParent;
	OnInitialize();
}
