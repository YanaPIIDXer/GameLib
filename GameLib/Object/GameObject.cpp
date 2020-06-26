#include "GameObject.h"
#include "../Scene/Scene.h"

// �R���X�g���N�^
GameObject::GameObject()
	: pScene(nullptr)
	, bIsDestroyed(false)
{
}

// �f�X�g���N�^
GameObject::~GameObject()
{
}

// ������
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

// �R���|�[�l���g�ǉ�
void GameObject::AddComponent(ObjectComponent *pComponent)
{
	Components.push_back(ComponentPtr(pComponent));
	if (pScene != nullptr)
	{
		pComponent->Initialize(this, pScene->GetComponentInitializer());
	}
}

// �I�u�W�F�N�g�̔j��
void GameObject::Destroy()
{
	if (bIsDestroyed) { return; }

	OnDestroy();
	bIsDestroyed = true;
}

// �X�V
void GameObject::UpdateObject()
{
	for (auto Cmp : Components)
	{
		Cmp->Update();
	}

	Update();
}

// �`��
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


// �ړ�
void GameObject::MoveWorld(float X, float Y, float Z)
{
	Trans.MoveWorld(X, Y, Z);
}
