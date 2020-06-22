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


// 初期化イベント
void TeapotComponent::OnInitialize(const ComponentInitializer &Initializer)
{
	D3DXCreateTeapot(Initializer.pD3DXDevices.lock()->pDevice, &pMesh, nullptr);
}
