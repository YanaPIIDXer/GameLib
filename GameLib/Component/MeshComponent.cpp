#include "MeshComponent.h"
#include "../Object/GameObject.h"

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
void MeshComponent::Render(D3DXRender *pRender)
{
	if (pMesh == nullptr) { return; }

	auto *pParent = GetParent();
	const auto &Trans = pParent->GetTransform();

	D3DXMATRIX Mat = Trans.GetD3DXMatrix();
	pRender->SetTransformMatrix(Mat);

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
