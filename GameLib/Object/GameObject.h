#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Math/Transform.h"

/**
 * @class GameObject
 * @brief �Q�[���I�u�W�F�N�g
 */
class GameObject
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	GameObject();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~GameObject() = 0;

private:

	// �p��
	Transform Trans;

};

#endif		// #ifndef GAMEOBJECT_H
