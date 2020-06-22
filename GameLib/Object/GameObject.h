#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Math/Transform.h"

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

	// 姿勢
	Transform Trans;

	// 破棄されたか？
	bool bIsDestroyed;

};

#endif		// #ifndef GAMEOBJECT_H
