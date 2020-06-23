#include "TeapotComponent.h"

// �R���X�g���N�^
TeapotComponent::TeapotComponent()
{
}

// �f�X�g���N�^
TeapotComponent::~TeapotComponent()
{
}


// �������C�x���g
void TeapotComponent::OnInitialize(const ComponentInitializer &Initializer)
{
	LPD3DXMESH pMesh = nullptr;
	D3DXCreateTeapot(Initializer.pD3DXDevices.lock()->pDevice, &pMesh, nullptr);
	SetMesh(pMesh);
}
