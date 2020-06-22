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

private:

	// ���݂̃V�[��
	std::unique_ptr<Scene> pCurrentScene;

};

#endif		// #ifndef SCENEEXECUTER_H
