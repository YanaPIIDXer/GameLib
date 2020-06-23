#include "MeshComponent.h"

// �R���X�g���N�^
MeshComponent::MeshComponent()
	: pMesh(nullptr)
{
}

// �f�X�g���N�^
MeshComponent::~MeshComponent()
{
	Release();
}

// �`��
void MeshComponent::Render()
{
	if (pMesh == nullptr) { return; }

	pMesh->DrawSubset(0);
}


// ���b�V�����Z�b�g
void MeshComponent::SetMesh(LPD3DXMESH pInMesh)
{
	Release();		// ��U���
	pMesh = pInMesh;
}


// ���
void MeshComponent::Release()
{
	if (pMesh != nullptr)
	{
		pMesh->Release();
		pMesh = nullptr;
	}
}
