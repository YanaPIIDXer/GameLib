#include "ObjectComponent.h"

// �R���X�g���N�^
ObjectComponent::ObjectComponent()
{
}

// �f�X�g���N�^
ObjectComponent::~ObjectComponent()
{
}

// ������
void ObjectComponent::Initialize(GameObject *pInParent, const ComponentInitializer &Initializer)
{
	pParent = pInParent;
	OnInitialize(Initializer);
}
