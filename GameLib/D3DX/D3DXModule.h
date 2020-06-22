#ifndef D3DXMODULE_H
#define D3DXMODULE_H

#include "d3dx9.h"
#include <memory>

/**
 * @struct D3DXDevices
 * @brief D3DXデバイス構造体
 */
struct D3DXDevices
{
	/**
	 * @brief D3DX
	 */
	LPDIRECT3D9 pD3DX;

	/**
	 * @brief D3DXデバイス
	 */
	LPDIRECT3DDEVICE9 pDevice;
};

typedef std::weak_ptr<D3DXDevices> D3DXDevicesPtr;

/**
 * @class D3DXModule
 * @brief D3DXの機能モジュールインタフェース
 */
class D3DXModule
{
public:

	/**
	 * @brief コンストラクタ
	 */
	D3DXModule();

	/**
	 * @brief デストラクタ
	 */
	virtual ~D3DXModule();

	/**
	 * @fn virtual const char *GetModuleName() const = 0
	 * @brief モジュール名を取得
	 * @returns モジュール名
	 */
	virtual const char *GetModuleName() const = 0;

	/**
	 * @fn void SetDevices(D3DXDevicesPtr pInDevices)
	 * @brief 各デバイスへの参照をセット
	 * @param[in] pInDevices デバイスへの参照
	 */
	void SetDevices(D3DXDevicesPtr pInDevices) { pDevices = pInDevices; }

protected:

	/**
	 * @fn LPDIRECT3D9 GetD3DX()
	 * @brief D3DX取得
	 * @return D3DX
	 */
	LPDIRECT3D9 GetD3DX() { return pDevices.lock()->pD3DX; }

	/**
	 * @fn LPDIRECT3DDEVICE9 GetDevice()
	 * @brief D3DXデバイス取得
	 * @return D3DXデバイス
	 */
	LPDIRECT3DDEVICE9 GetDevice() { return pDevices.lock()->pDevice; }

private:

	// 各デバイスへの参照
	D3DXDevicesPtr pDevices;

};

#endif		// #ifndef D3DXMODULE_H
