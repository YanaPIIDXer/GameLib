#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <windows.h>
#include <string>

/**
 * @class Application
 * @brief �A�v���P�[�V�����N���X
 */
class Application
{
public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInInst �C���X�^���X�n���h��
	 * @param[in] InClassName �E�B���h�E�N���X��
	 * @param[in] WindowTitle �E�B���h�E�̃^�C�g��
	 * @param[in] X �E�B���h�E�̂w���W
	 * @param[in] X �E�B���h�E�̂x���W
	 * @param[in] Width �E�B���h�E�̕�
	 * @param[in] Height �E�B���h�E�̍���
	 */
	Application(HINSTANCE pInInst, const std::string &InClassName, const std::string &WindowTitle, int X, int Y, int Width, int Height);

	/**
	 * @brief �f�X�g���N�^
	 */
	~Application();

	/**
	 * @fn void Run();
	 * @brief ���C�����[�v�̎��s
	 */
	void Run();

private:

	// �C���X�^���X�n���h��
	HINSTANCE pInst;

	// �E�B���h�E�N���X��.
	std::string ClassName;

};

#endif		// #ifndef __APPLICATION_H__
