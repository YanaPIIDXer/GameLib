#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <windows.h>
#include <string>

/**
 * @class Application
 * @brief アプリケーションクラス
 */
class Application
{
public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInInst インスタンスハンドル
	 * @param[in] InClassName ウィンドウクラス名
	 * @param[in] WindowTitle ウィンドウのタイトル
	 * @param[in] X ウィンドウのＸ座標
	 * @param[in] X ウィンドウのＹ座標
	 * @param[in] Width ウィンドウの幅
	 * @param[in] Height ウィンドウの高さ
	 */
	Application(HINSTANCE pInInst, const std::string &InClassName, const std::string &WindowTitle, int X, int Y, int Width, int Height);

	/**
	 * @brief デストラクタ
	 */
	~Application();

	/**
	 * @fn void Run();
	 * @brief メインループの実行
	 */
	void Run();

private:

	// インスタンスハンドル
	HINSTANCE pInst;

	// ウィンドウクラス名.
	std::string ClassName;

};

#endif		// #ifndef __APPLICATION_H__
