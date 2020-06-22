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
	 * @fn void Initialize(GameObject *pInParent)
	 * @brief ������
	 * @param[in] pInParent �e
	 */
	void Initialize(GameObject *pInParent);

	/**
	 * @fn bool IsInitialized() const
	 * @brief ����������Ă��邩�H
	 * @return ����������Ă�����true
	 */
	bool IsInitialized() const { return (pParent != nullptr); }

protected:

	/**
	 * @fn virtual void OnInitialize()
	 * @brief �������C�x���g
	 */
	virtual void OnInitialize() {}

private:

	// �e
	GameObject *pParent;

};

#endif		// #ifndef OBJECTCOMPONENT_H
