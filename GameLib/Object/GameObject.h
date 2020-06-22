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
	virtual ~GameObject();

	/**
	 * @fn const Transform GetTransform() const
	 * @brief 姿勢の取得
	 * @return 姿勢
	 */
	const Transform GetTransform() const { return Trans; }

private:

	// 姿勢
	Transform Trans;

};

#endif		// #ifndef GAMEOBJECT_H
