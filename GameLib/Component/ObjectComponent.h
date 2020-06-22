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
	ObjectComponent();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~ObjectComponent() = 0;

	/**
	 * @fn void SetParent(GameObject *pInParent)
	 * @brief �e��ݒ�
	 * @param[in] pInParent �e
	 */
	void SetParent(GameObject *pInParent) { pParent = pInParent; }

private:

	// �e
	GameObject *pParent;

};

#endif		// #ifndef OBJECTCOMPONENT_H
