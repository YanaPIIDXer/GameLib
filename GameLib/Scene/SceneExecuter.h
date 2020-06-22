#ifndef SCENEEXECUTER_H
#define SCENEEXECUTER_H

#include <memory>

class Scene;

/**
 * @class SceneExecuter
 * @brief シーン処理を実行するクラス
 */
class SceneExecuter
{
public:

	/**
	 * @brief コンストラクタ
	 */
	SceneExecuter();

	/**
	 * @brief デストラクタ
	 */
	~SceneExecuter();

	/**
	 * @fn void Poll()
	 * @brief 毎フレーム実行する処理
	 */
	void Poll();

	/**
	 * @fn void SetNextScene(Scene *pScene)
	 * @brief 次のシーンに遷移
	 * @param[in] pScene 次のシーン
	 */
	void SetNextScene(Scene *pScene);

private:

	// 現在のシーン
	std::unique_ptr<Scene> pCurrentScene;

	// 次のシーン
	std::unique_ptr<Scene> pNextScene;

};

#endif		// #ifndef SCENEEXECUTER_H
