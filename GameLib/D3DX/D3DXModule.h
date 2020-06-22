#ifndef D3DXMODULE_H
#define D3DXMODULE_H

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

#endif		// #ifndef D3DXMODULE_H
