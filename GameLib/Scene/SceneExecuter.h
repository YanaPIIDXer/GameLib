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

private:

	// 現在のシーン
	std::unique_ptr<Scene> pCurrentScene;

};

#endif		// #ifndef SCENEEXECUTER_H
