#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Math/Transform.h"
#include "../Component/ObjectComponent.h"
#include <vector>
#include <memory>

class Scene;
class D3DXRender;

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

	/**
	 * @fn void UpdateObject()
	 * @brief オブジェクト更新
	 *        ※関数名に「Object」を付けるのは相応しくないが、
	 *          仮想関数の方を「Update」としたい為こうしている。
	 */
	void UpdateObject();

	/**
	 * @fn void Render()
	 * @brief 描画
	 * @param[in] pRender 描画用インタフェース
	 */
	void Render(D3DXRender *pRender);

	/**
	 * @fn const Transform &GetTransform() const
	 * @brief 姿勢を取得
	 * @return 姿勢
	 */
	const Transform &GetTransform() const { return Trans; }

protected:

	/**
	 * @fn virtual void Update()
	 * @brief 更新
	 */
	virtual void Update() {}

	/**
	 * @fn virtual void OnDestroy()
	 * @brief 破棄イベント
	 */
	virtual void OnDestroy() {}

	/**
	 * @fn void MoveWorld(float X, float Y, float Z)
	 * @brief ワールド軸を使った移動
	 * @param[in] X Ｘ方向
	 * @param[in] Y Ｙ方向
	 * @param[in] Z Ｚ方向
	 */
	void MoveWorld(float X, float Y, float Z);

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
