#ifndef APPLICATION_H
#define APPLICATION_H

#include <windows.h>
#include <string>
#include "../D3DX/D3DXCore.h"
#include "../Scene/SceneExecuter.h"
#include <map>

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
	 */
	Application(HINSTANCE pInInst, const std::string &InClassName);

	/**
	 * @brief デストラクタ
	 */
	~Application();

	/**
	 * @fn bool Initialize( const std::string &WindowTitle, int X, int Y, int Width, int Height);
	 * @brief 初期化
	 * @param[in] WindowTitle ウィンドウのタイトル
	 * @param[in] X ウィンドウのＸ座標
	 * @param[in] X ウィンドウのＹ座標
	 * @param[in] Width ウィンドウの幅
	 * @param[in] Height ウィンドウの高さ
	 * @param[in] pInitialScene 初期シーン
	 * @return 成功したらtrueを返す。
	 */
	bool Initialize(const std::string &WindowTitle, int X, int Y, int Width, int Height, Scene *pInitialScene = nullptr);

	/**
	 * @fn void Run();
	 * @brief メインループの実行
	 */
	void Run();

	/**
	 * @fn void SetNextScene(Scene *pScene)
	 * @brief 次のシーンに遷移
	 * @param[in] pScene 次のシーン
	 */
	void SetNextScene(Scene *pScene);

	/**
	 * @fn void AddD3DXModule(ID3DXModule *pModule)
	 * @brief D3DXモジュールを追加
	 * @param[in] pModule モジュール
	 */
	void AddD3DXModule(D3DXModule *pModule);

	/**
	 * @fn T *GetD3DXModule(const char *pModuleName)
	 * @brief D3DXモジュールを取得
	 * @param[in] pModuleName モジュール名
	 * @return モジュール
	 */
	template<class T>
	T *GetD3DXModule(const char *pModuleName) const
	{
		auto KeyValue = D3DXModules.find(pModuleName);
		if (KeyValue == D3DXModules.end()) { return nullptr; }

		D3DXModule *pModule = KeyValue->second.get();
		return static_cast<T *>(pModule);
	}

	/**
	 * @fn D3DXDevicesPtr GetD3DXDevices() const 
	 * @brief D3DXデバイスを取得
	 * @return D3DXデバイス
	 */
	D3DXDevicesPtr GetD3DXDevices() const { return Core.GetDevices(); }

private:

	// インスタンスハンドル
	HINSTANCE pInst;

	// ウィンドウクラス名.
	std::string ClassName;

	// シーン処理
	SceneExecuter SceneExec;

	// D3DXコア
	D3DXCore Core;

	// D3DXモジュールのマップ
	std::map<const char *, std::unique_ptr<D3DXModule>> D3DXModules;

	
	// D3DXモジュール初期化
	void InitD3DXModules();

	// メッセージプロシージャ
	LRESULT MessageProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK StaticMessageProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

};

#endif		// #ifndef APPLICATION_H
