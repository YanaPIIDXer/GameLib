#include "D3DXCore.h"

// コンストラクタ
D3DXCore::D3DXCore()
	: pDevices(new D3DXDevices())
{
}

// デストラクタ
D3DXCore::~D3DXCore()
{
	Release();
}

// 初期化
bool D3DXCore::Initialize(HWND hWnd)
{
	// 一旦解放。
	Release();

	pDevices->pD3DX = Direct3DCreate9(D3D_SDK_VERSION);
	if (pDevices->pD3DX == nullptr) { return false; }

	D3DPRESENT_PARAMETERS Params;
	ZeroMemory(&Params, sizeof(Params));
	Params.Windowed = TRUE;
	Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Params.BackBufferFormat = D3DFMT_UNKNOWN;
	Params.EnableAutoDepthStencil = TRUE;
	Params.AutoDepthStencilFormat = D3DFMT_D16;

	if(FAILED(pDevices->pD3DX->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &Params, &pDevices->pDevice)) &&
	   FAILED(pDevices->pD3DX->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &Params, &pDevices->pDevice))) { return false; }

	pDevices->pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	return true;
}


// 解放
void D3DXCore::Release()
{
	if (pDevices->pD3DX != nullptr)
	{
		pDevices->pD3DX->Release();
		pDevices->pD3DX = nullptr;
	}

	if (pDevices->pDevice != nullptr)
	{
		pDevices->pDevice->Release();
		pDevices->pDevice = nullptr;
	}
}
