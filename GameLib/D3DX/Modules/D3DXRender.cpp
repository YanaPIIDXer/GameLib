#include "D3DXRender.h"

// �R���X�g���N�^
D3DXRender::D3DXRender()
	: bIsRendering(false)
	, ClearColor(D3DCOLOR_XRGB(0, 0, 255))
{
}

// �f�X�g���N�^
D3DXRender::~D3DXRender()
{
}

// �`��J�n
void D3DXRender::Begin()
{
	if (bIsRendering) { return; }

	auto *pDevice = GetDevice();
	pDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, ClearColor, 1.0f, 0);
	bIsRendering = pDevice->BeginScene();
}

// �`��I��
void D3DXRender::End()
{
	if (!bIsRendering) { return; }

	auto *pDevice = GetDevice();
	pDevice->EndScene();
	pDevice->Present(nullptr, nullptr, nullptr, nullptr);

	bIsRendering = false;
}

