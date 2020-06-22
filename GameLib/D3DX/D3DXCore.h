#ifndef D3DXCORE_H
#define D3DXCORE_H

#include "d3dx9.h"
#include "D3DXModule.h"

/**
 * @class D3DXCore
 * @brief DirectXのコア部分。
 *        デバイスのインスタンス等。
 */
class D3DXCore : public ID3DXModule
{
public:

	/**
	 * @brief コンストラクタ
	 */
	D3DXCore();

	/**
	 * @brief デストラクタ
	 */
	virtual ~D3DXCore();

	/**
	 * @fn virtual const char *GetModuleName() const override
	 * @brief モジュール名を取得
	 * @returns モジュール名
	 */
	virtual const char *GetModuleName() const override { return "Core"; }

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
