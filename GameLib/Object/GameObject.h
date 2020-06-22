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

private:

	// 姿勢
	Transform Trans;

};

#endif		// #ifndef GAMEOBJECT_H
