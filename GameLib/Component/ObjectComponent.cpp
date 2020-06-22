#include "ObjectComponent.h"

// コンストラクタ
ObjectComponent::ObjectComponent(GameObject *pInParent)
	: pParent(pInParent)
{
}

// デストラクタ
ObjectComponent::~ObjectComponent()
{
}
