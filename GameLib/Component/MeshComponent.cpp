#include "MeshComponent.h"
#include "../Object/GameObject.h"

// コンストラクタ
MeshComponent::MeshComponent()
	: pMesh(nullptr)
{
}

// デストラクタ
MeshComponent::~MeshComponent()
{
	Release();
}

// 描画
void MeshComponent::Render(D3DXRender *pRender)
{
	if (pMesh == nullptr) { return; }

	auto *pParent = GetParent();
	const auto &Trans = pParent->GetTransform();

	D3DXMATRIX Mat = Trans.GetD3DXMatrix();
	pRender->SetTransformMatrix(Mat);

	pMesh->DrawSubset(0);
}


// メッシュをセット
void MeshComponent::SetMesh(LPD3DXMESH pInMesh)
{
	Release();		// 一旦解放
	pMesh = pInMesh;
}


// 解放
void MeshComponent::Release()
{
	if (pMesh != nullptr)
	{
		pMesh->Release();
		pMesh = nullptr;
	}
}
