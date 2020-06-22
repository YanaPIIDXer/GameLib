#include "TeapotComponent.h"

// コンストラクタ
TeapotComponent::TeapotComponent()
	: pMesh(nullptr)
{
}

// デストラクタ
TeapotComponent::~TeapotComponent()
{
	if (pMesh != nullptr)
	{
		pMesh->Release();
		pMesh = nullptr;
	}
}

// 描画
void TeapotComponent::Render()
{
	pMesh->DrawSubset(0);
}


// 初期化イベント
void TeapotComponent::OnInitialize(const ComponentInitializer &Initializer)
{
	D3DXCreateTeapot(Initializer.pD3DXDevices.lock()->pDevice, &pMesh, nullptr);
}
