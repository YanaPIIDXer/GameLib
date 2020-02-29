#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <windows.h>
#include <string>
#include "../D3DX/D3DXCore.h"

class Game;

/**
 * @class Application
 * @brief �A�v���P�[�V�����N���X
 */
class Application
{
public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInGame �Q�[��
	 * @param[in] pInInst �C���X�^���X�n���h��
	 * @param[in] InClassName �E�B���h�E�N���X��
	 */
	Application(Game *pInGame, HINSTANCE pInInst, const std::string &InClassName);

	/**
	 * @brief �f�X�g���N�^
	 */
	~Application();

	/**
	 * @fn bool Initialize( const std::string &WindowTitle, int X, int Y, int Width, int Height);
	 * @brief ������
	 * @param[in] WindowTitle �E�B���h�E�̃^�C�g��
	 * @param[in] X �E�B���h�E�̂w���W
	 * @param[in] X �E�B���h�E�̂x���W
	 * @param[in] Width �E�B���h�E�̕�
	 * @param[in] Height �E�B���h�E�̍���
	 * @return ����������true��Ԃ��B
	 */
	bool Initialize(const std::string &WindowTitle, int X, int Y, int Width, int Height);

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

	// D3DX
	D3DXCore D3DX;

	// �Q�[��
	Game *pGame;


	// ���b�Z�[�W�v���V�[�W��
	LRESULT MessageProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK StaticMessageProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

};

#endif		// #ifndef __APPLICATION_H__
