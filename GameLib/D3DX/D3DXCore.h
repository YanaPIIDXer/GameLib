#ifndef D3DXCORE_H
#define D3DXCORE_H

#include "d3dx9.h"

/**
 * @class D3DXCore
 * @brief DirectXのコア部分。
 *        デバイスのインスタンス等。
 */
class D3DXCore
{
public:

	/**
	 * @brief コンストラクタ
	 */
	D3DXCore();

	/**
	 * @brief デストラクタ
	 */
	~D3DXCore();

	/**
	 * @fn bool Initialize();
	 * @brief 初期化
	 * @param[in] hWnd ウィンドウハンドル
	 * @return 成功したらtrueを返す。
	 */
	bool Initialize(HWND hWnd);

private:
	
	// D3DX
	LPDIRECT3D9 pD3DX;

	// D3DXデバイス
	LPDIRECT3DDEVICE9 pDevice;


	// 解放
	void Release();

};

#endif		// #ifndef D3DXCORE_H
