#ifndef SCENE_H
#define SCENE_H

class Application;

/**
 * @class Scene
 * @brief シーンクラス。
 *        各シーンはこのクラスを派生させて実装する。
 */
class Scene
{
public:

	/**
	 * @brief コンストラクタ
	 */
	Scene();

	/**
	 * @brief デストラクタ
	 */
	virtual ~Scene() = 0;

	/**
	 * @fn void Poll()
	 * @brief 毎フレームの処理
	 */
	void Poll();

	/**
	 * @fn void SetNextScene(Scene *pScene)
	 * @brief 次のシーンに遷移
	 * @param[in] pScene 次のシーン
	 */
	void SetNextScene(Scene *pNextScene);

	/**
	 * @fn void SetApplication(Application *pApp)
	 * @brief Applicationへの参照をセット
	 * @param[in] pApp Applicationへの参照
	 */
	void SetApplication(Application *pApp) { pApplication = pApp; }

protected:

private:

	// Applicationへの参照
	Application *pApplication;


	// 描画
	void Render();

};

#endif		// #ifndef SCENE_H
