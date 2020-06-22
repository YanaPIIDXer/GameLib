#ifndef D3DXCORE_H
#define D3DXCORE_H

#include "D3DXModule.h"

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

	/**
	 * @fn D3DXDevicesPtr GetDevices() const
	 * @brief デバイス取得
	 * @return デバイス
	 */
	D3DXDevicesPtr GetDevices() const { return pDevices; }

private:
	
	// デバイス
	std::shared_ptr<D3DXDevices> pDevices;

	// 解放
	void Release();

};

#endif		// #ifndef D3DXCORE_H
