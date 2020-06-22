#ifndef OBJECTCOMPONENT_H
#define OBJECTCOMPONENT_H

class GameObject;

/**
 * @class ObjectComponent
 * @brief �I�u�W�F�N�g�ɓ\��t����R���|�[�l���g
 */
class ObjectComponent
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	ObjectComponent(GameObject *pInParent);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~ObjectComponent() = 0;

private:

	// �e
	GameObject *pParent;

};

#endif		// #ifndef OBJECTCOMPONENT_H
