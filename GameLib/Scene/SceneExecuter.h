#ifndef SCENEEXECUTER_H
#define SCENEEXECUTER_H

#include <memory>

class Scene;

/**
 * @class SceneExecuter
 * @brief �V�[�����������s����N���X
 */
class SceneExecuter
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	SceneExecuter();

	/**
	 * @brief �f�X�g���N�^
	 */
	~SceneExecuter();

	/**
	 * @fn void Poll()
	 * @brief ���t���[�����s���鏈��
	 */
	void Poll();

	/**
	 * @fn void SetNextScene(Scene *pScene)
	 * @brief ���̃V�[���ɑJ��
	 * @param[in] pScene ���̃V�[��
	 */
	void SetNextScene(Scene *pScene);

private:

	// ���݂̃V�[��
	std::unique_ptr<Scene> pCurrentScene;

	// ���̃V�[��
	std::unique_ptr<Scene> pNextScene;

};

#endif		// #ifndef SCENEEXECUTER_H
