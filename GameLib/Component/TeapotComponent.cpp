#include "TeapotComponent.h"

// �R���X�g���N�^
TeapotComponent::TeapotComponent()
	: pMesh(nullptr)
{
}

// �f�X�g���N�^
TeapotComponent::~TeapotComponent()
{
	if (pMesh != nullptr)
	{
		pMesh->Release();
		pMesh = nullptr;
	}
}


// �������C�x���g
void TeapotComponent::OnInitialize(const ComponentInitializer &Initializer)
{
	auto bResult = D3DXCreateTeapot(Initializer.pD3DXDevices.lock()->pDevice, &pMesh, nullptr);
}
