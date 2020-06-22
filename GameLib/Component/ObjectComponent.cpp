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
void ObjectComponent::Initialize(GameObject *pInParent, const ComponentInitializer &Initializer)
{
	pParent = pInParent;
	OnInitialize(Initializer);
}
