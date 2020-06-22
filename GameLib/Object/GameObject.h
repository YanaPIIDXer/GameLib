#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Math/Transform.h"
#include "../Component/ObjectComponent.h"
#include <vector>
#include <memory>

class Scene;

/**
 * @class GameObject
 * @brief ゲームオブジェクト
 */
class GameObject
{
public:

	/**
	 * @brief コンストラクタ
	 */
	GameObject();

	/**
	 * @brief デストラクタ
	 */
	virtual ~GameObject() = 0;

	/**
	 * @fn void Initialize(Scene *pInScene)
	 * @brief 初期化
	 * @param[in] pInScene シーン
	 */
	void Initialize(Scene *pInScene);

	/**
	 * @fn bool IsInitialized() const
	 * @brief 初期化されているか？
	 * @return 初期化されているならtrue
	 */
	bool IsInitialized() const { return (pScene != nullptr); }

	/**
	 * @fn void AddComponent(ObjectComponent *pComponent)
	 * @brief コンポーネント追加
	 * @param[in] pComponent コンポーネント
	 */
	void AddComponent(ObjectComponent *pComponent);

	/**
	 * @fn void Destroy()
	 * @brief オブジェクトの破棄
	 */
	void Destroy();

	/**
	 * @fn bool IsDestroyed() const
	 * @brief 破棄されているか？
	 * @return 破棄されていたらtrue
	 */
	bool IsDestroyed() const { return bIsDestroyed; }

protected:

	/**
	 * @fn virtual void OnDestroy()
	 * @brief 破棄イベント
	 */
	virtual void OnDestroy() {}

private:

	// シーンへのポインタ
	Scene *pScene;

	// 姿勢
	Transform Trans;

	// 破棄されたか？
	bool bIsDestroyed;

	// コンポーネント
	typedef std::shared_ptr<ObjectComponent> ComponentPtr;
	std::vector<ComponentPtr> Components;

};

#endif		// #ifndef GAMEOBJECT_H
