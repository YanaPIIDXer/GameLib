#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Math/Transform.h"
#include "../Component/ObjectComponent.h"
#include <vector>
#include <memory>

class Scene;

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
	 * @fn void Initialize(Scene *pInScene)
	 * @brief ������
	 * @param[in] pInScene �V�[��
	 */
	void Initialize(Scene *pInScene);

	/**
	 * @fn bool IsInitialized() const
	 * @brief ����������Ă��邩�H
	 * @return ����������Ă���Ȃ�true
	 */
	bool IsInitialized() const { return (pScene != nullptr); }

	/**
	 * @fn void AddComponent(ObjectComponent *pComponent)
	 * @brief �R���|�[�l���g�ǉ�
	 * @param[in] pComponent �R���|�[�l���g
	 */
	void AddComponent(ObjectComponent *pComponent);

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

	// �V�[���ւ̃|�C���^
	Scene *pScene;

	// �p��
	Transform Trans;

	// �j�����ꂽ���H
	bool bIsDestroyed;

	// �R���|�[�l���g
	typedef std::shared_ptr<ObjectComponent> ComponentPtr;
	std::vector<ComponentPtr> Components;

};

#endif		// #ifndef GAMEOBJECT_H
