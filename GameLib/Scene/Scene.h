#ifndef SCENE_H
#define SCENE_H

/**
 * @class Scene
 * @brief �V�[���N���X�B
 *        �e�V�[���͂��̃N���X��h�������Ď�������B
 */
class Scene
{
public:

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~Scene() = 0;

	/**
	 * @fn void Poll()
	 * @brief ���t���[���̏���
	 */
	void Poll();

protected:

private:
};

#endif		// #ifndef SCENE_H
