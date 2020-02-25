#include "D3DXCore.h"

// コンストラクタ
D3DXCore::D3DXCore()
	: pD3DX(nullptr)
	, pDevice(nullptr)
{
}

// デストラクタ
D3DXCore::~D3DXCore()
{
	if (pD3DX != nullptr)
	{
		pD3DX->Release();
		pD3DX = nullptr;
	}

	if (pDevice != nullptr)
	{
		pDevice->Release();
		pDevice = nullptr;
	}
}

// 初期化
bool D3DXCore::Initialize(HWND hWnd)
{
	pD3DX = Direct3DCreate9(D3D_SDK_VERSION);
	if (pD3DX == nullptr) { return false; }

	D3DPRESENT_PARAMETERS Params;
	ZeroMemory(&Params, sizeof(Params));
	Params.Windowed = TRUE;
	Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Params.BackBufferFormat = D3DFMT_UNKNOWN;
	Params.EnableAutoDepthStencil = TRUE;
	Params.AutoDepthStencilFormat = D3DFMT_D16;

	if(FAILED(pD3DX->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &Params, &pDevice)) &&
	   FAILED(pD3DX->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &Params, &pDevice))) { return false; }

	pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	return true;
}
