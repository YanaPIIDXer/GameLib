#include "TeapotComponent.h"

// コンストラクタ
TeapotComponent::TeapotComponent()
{
}

// デストラクタ
TeapotComponent::~TeapotComponent()
{
}


// 初期化イベント
void TeapotComponent::OnInitialize(const ComponentInitializer &Initializer)
{
	LPD3DXMESH pMesh = nullptr;
	D3DXCreateTeapot(Initializer.pD3DXDevices.lock()->pDevice, &pMesh, nullptr);
	SetMesh(pMesh);
}
