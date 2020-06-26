#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>
#include "../Component/ObjectComponent.h"

class Application;
class GameObject;

/**
 * @class Scene
 * @brief �V�[���N���X�B
 *        �e�V�[���͂��̃N���X��h�������Ď�������B
 */
class Scene
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	Scene();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~Scene() = 0;

	/**
	 * @fn void Initialize(Application *pApp)
	 * @brief ������
	 * @param[in] pApp Application�ւ̎Q��
	 */
	void Initialize(Application *pApp);

	/**
	 * @fn void AddObject(GameObject *pObject)
	 * @brief �I�u�W�F�N�g�ǉ�
	 * @param[in] pObject �I�u�W�F�N�g
	 */
	void AddObject(GameObject *pObject);

	/**
	 * @fn void Poll()
	 * @brief ���t���[���̏���
	 */
	void Poll();

	/**
	 * @fn void SetNextScene(Scene *pScene)
	 * @brief ���̃V�[���ɑJ��
	 * @param[in] pScene ���̃V�[��
	 */
	void SetNextScene(Scene *pNextScene);

	/**
	 * @fn const ComponentInitializer &GetComponentInitializer() const 
	 * @brief �R���|�[�l���g�������I�u�W�F�N�g�擾
	 * @return �R���|�[�l���g�������I�u�W�F�N�g
	 */
	const ComponentInitializer &GetComponentInitializer() const { return CmpInitializer; }

protected:

private:

	// Application�ւ̎Q��
	Application *pApplication;

	// �R���|�[�l���g�������I�u�W�F�N�g
	ComponentInitializer CmpInitializer;

	// �I�u�W�F�N�g
	typedef std::shared_ptr<GameObject> ObjectPtr;
	std::vector<ObjectPtr> Objects;

	// �O�t���[���̎���
	DWORD PrevTime;


	// �`��
	void Render();

};

#endif		// #ifndef SCENE_H
