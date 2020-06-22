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

	/**
	 * @fn const Transform GetTransform() const
	 * @brief �p���̎擾
	 * @return �p��
	 */
	const Transform GetTransform() const { return Trans; }

private:

	// �p��
	Transform Trans;

};

#endif		// #ifndef GAMEOBJECT_H
