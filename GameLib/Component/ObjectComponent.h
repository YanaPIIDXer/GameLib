#ifndef OBJECTCOMPONENT_H
#define OBJECTCOMPONENT_H

class GameObject;

#include "../D3DX/D3DXModule.h"

/**
 * @struct ComponentInitializer
 * @brief �R���|�[�l���g�������p�̃I�u�W�F�N�g
 */
struct ComponentInitializer
{
	/**
	 * @brief D3DX�f�o�C�X
	 */
	D3DXDevicesPtr pD3DXDevices;
};

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
	 * @fn void Initialize(GameObject *pInParent, const ComponentInitializer &Initializer)
	 * @brief ������
	 * @param[in] pInParent �e
	 * @param[in] Initializer �������I�u�W�F�N�g
	 */
	void Initialize(GameObject *pInParent, const ComponentInitializer &Initializer);

	/**
	 * @fn bool IsInitialized() const
	 * @brief ����������Ă��邩�H
	 * @return ����������Ă�����true
	 */
	bool IsInitialized() const { return (pParent != nullptr); }

	/**
	 * @fn virtual bool IsRenderComponent() const
	 * @brief �`��R���|�[�l���g���H
	 * @return �`��R���|�[�l���g�Ȃ�true
	 */
	virtual bool IsRenderComponent() const { return false; }

	/**
	 * @fn virtual void Update()
	 * @brief �X�V
	 */
	virtual void Update() {}

	/**
	 * @fn virtual void Render()
	 * @brief �`��
	 */
	virtual void Render() {}

protected:

	/**
	 * @fn virtual void OnInitialize(const ComponentInitializer &Initializer)
	 * @brief �������C�x���g
	 * @param[in] Initializer �������I�u�W�F�N�g
	 */
	virtual void OnInitialize(const ComponentInitializer &Initializer) {}

	/**
	 * @fn GameObject *GetParent() const
	 * @brief �e���擾
	 * @return �e
	 */
	GameObject *GetParent() const { return pParent; }

private:

	// �e
	GameObject *pParent;

};

#endif		// #ifndef OBJECTCOMPONENT_H
