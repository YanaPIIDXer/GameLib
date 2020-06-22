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

	/**
	 * @fn void SetClearColor(D3DCOLOR InClearColor)
	 * @brief クリア時の塗り潰し色を設定
	 * @param[in] R 赤
	 * @param[in] G 緑
	 * @param[in] B 青
	 */
	void SetClearColor(BYTE R, BYTE G, BYTE B) { ClearColor = D3DCOLOR_XRGB(R, G, B); }

private:

	// 描画中？
	bool bIsRendering;

	// クリア時の塗り潰し色
	D3DCOLOR ClearColor;

};

#endif		// #ifndef D3DXRENDER_H
