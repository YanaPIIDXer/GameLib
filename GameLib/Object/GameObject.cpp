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

// �I�u�W�F�N�g�̔j��
void GameObject::Destroy()
{
	if (bIsDestroyed) { return; }

	OnDestroy();
	bIsDestroyed = true;
}
