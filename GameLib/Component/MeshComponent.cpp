#include "MeshComponent.h"

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
void MeshComponent::Render()
{
	if (pMesh == nullptr) { return; }

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
