#ifndef SCENE_H
#define SCENE_H

class Application;

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
	 * @fn void SetApplication(Application *pApp)
	 * @brief Application�ւ̎Q�Ƃ��Z�b�g
	 * @param[in] pApp Application�ւ̎Q��
	 */
	void SetApplication(Application *pApp) { pApplication = pApp; }

protected:

private:

	// Application�ւ̎Q��
	Application *pApplication;

};

#endif		// #ifndef SCENE_H
