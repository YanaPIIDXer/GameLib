#ifndef D3DXRENDER_H
#define D3DXRENDER_H

#include "../D3DXModule.h"

/**
 * @class D3DXRender
 * @brief 描画モジュール
 */
class D3DXRender : public D3DXModule
{
public:

	/**
	 * @brief コンストラクタ
	 */
	D3DXRender();

	/**
	 * @brief デストラクタ
	 */
	virtual ~D3DXRender();

	/**
	 * @fn virtual const char *GetModuleName() const override
	 * @brief モジュール名を取得
	 * @returns モジュール名
	 */
	virtual const char *GetModuleName() const override { return "Render"; }

	/**
	 * @fn void Begin()
	 * @brief 描画開始
	 */
	void Begin();

	/**
	 * @fn void End()
	 * @brief 描画終了
	 */
	void End();

private:

	// 描画中？
	bool bIsRendering;

};

#endif		// #ifndef D3DXRENDER_H
