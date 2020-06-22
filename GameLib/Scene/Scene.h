#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

class Application;
class GameObject;

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
	 * @fn void Initialize(Application *pApp)
	 * @brief 初期化
	 * @param[in] pApp Applicationへの参照
	 */
	void Initialize(Application *pApp);

	/**
	 * @fn void AddObject(GameObject *pObject)
	 * @brief オブジェクト追加
	 * @param[in] pObject オブジェクト
	 */
	void AddObject(GameObject *pObject);

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

protected:

private:

	// Applicationへの参照
	Application *pApplication;

	// オブジェクト
	typedef std::shared_ptr<GameObject> ObjectPtr;
	std::vector<ObjectPtr> Objects;


	// 描画
	void Render();

};

#endif		// #ifndef SCENE_H
