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
	 * @fn void Destroy()
	 * @brief �I�u�W�F�N�g�̔j��
	 */
	void Destroy();

	/**
	 * @fn bool IsDestroyed() const
	 * @brief �j������Ă��邩�H
	 * @return �j������Ă�����true
	 */
	bool IsDestroyed() const { return bIsDestroyed; }

protected:

	/**
	 * @fn virtual void OnDestroy()
	 * @brief �j���C�x���g
	 */
	virtual void OnDestroy() {}

private:

	// �p��
	Transform Trans;

	// �j�����ꂽ���H
	bool bIsDestroyed;

};

#endif		// #ifndef GAMEOBJECT_H
