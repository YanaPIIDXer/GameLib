#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

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

protected:

private:

	// Application�ւ̎Q��
	Application *pApplication;

	// �I�u�W�F�N�g
	typedef std::shared_ptr<GameObject> ObjectPtr;
	std::vector<ObjectPtr> Objects;


	// �`��
	void Render();

};

#endif		// #ifndef SCENE_H
