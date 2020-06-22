#ifndef D3DXMODULE_H
#define D3DXMODULE_H

#include <memory>

/**
 * @class ID3DXModule
 * @brief D3DXの機能モジュールインタフェース
 */
class ID3DXModule
{
public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~ID3DXModule() {}

	/**
	 * @fn virtual const char *GetModuleName() const = 0
	 * @brief モジュール名を取得
	 * @returns モジュール名
	 */
	virtual const char *GetModuleName() const = 0;

};

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

#endif		// #ifndef D3DXMODULE_H
