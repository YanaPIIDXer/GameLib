#include "GameObject.h"

// �R���X�g���N�^
GameObject::GameObject()
	: bIsDestroyed(false)
{
}

// �f�X�g���N�^
GameObject::~GameObject()
{
}

// �R���|�[�l���g�ǉ�
void GameObject::AddComponent(ObjectComponent *pComponent)
{
	pComponent->SetParent(this);
	Components.push_back(ComponentPtr(pComponent));
}

// �I�u�W�F�N�g�̔j��
void GameObject::Destroy()
{
	if (bIsDestroyed) { return; }

	OnDestroy();
	bIsDestroyed = true;
}
