#ifndef APPLICATION_H
#define APPLICATION_H

#include <windows.h>
#include <string>
#include "../D3DX/D3DXCore.h"
#include "../Scene/SceneExecuter.h"
#include <map>

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
	 */
	Application(HINSTANCE pInInst, const std::string &InClassName);

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
	 * @param[in] pInitialScene �����V�[��
	 * @return ����������true��Ԃ��B
	 */
	bool Initialize(const std::string &WindowTitle, int X, int Y, int Width, int Height, Scene *pInitialScene = nullptr);

	/**
	 * @fn void Run();
	 * @brief ���C�����[�v�̎��s
	 */
	void Run();

	/**
	 * @fn void SetNextScene(Scene *pScene)
	 * @brief ���̃V�[���ɑJ��
	 * @param[in] pScene ���̃V�[��
	 */
	void SetNextScene(Scene *pScene);

	/**
	 * @fn void AddD3DXModule(ID3DXModule *pModule)
	 * @brief D3DX���W���[����ǉ�
	 * @param[in] pModule ���W���[��
	 */
	void AddD3DXModule(D3DXModule *pModule);

	/**
	 * @fn T *GetD3DXModule(const char *pModuleName)
	 * @brief D3DX���W���[�����擾
	 * @param[in] pModuleName ���W���[����
	 * @return ���W���[��
	 */
	template<class T>
	T *GetD3DXModule(const char *pModuleName) const
	{
		auto KeyValue = D3DXModules.find(pModuleName);
		if (KeyValue == D3DXModules.end()) { return nullptr; }

		D3DXModule *pModule = KeyValue->second.get();
		return static_cast<T *>(pModule);
	}

	/**
	 * @fn D3DXDevicesPtr GetD3DXDevices() const 
	 * @brief D3DX�f�o�C�X���擾
	 * @return D3DX�f�o�C�X
	 */
	D3DXDevicesPtr GetD3DXDevices() const { return Core.GetDevices(); }

private:

	// �C���X�^���X�n���h��
	HINSTANCE pInst;

	// �E�B���h�E�N���X��.
	std::string ClassName;

	// �V�[������
	SceneExecuter SceneExec;

	// D3DX�R�A
	D3DXCore Core;

	// D3DX���W���[���̃}�b�v
	std::map<const char *, std::unique_ptr<D3DXModule>> D3DXModules;

	
	// D3DX���W���[��������
	void InitD3DXModules();

	// ���b�Z�[�W�v���V�[�W��
	LRESULT MessageProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK StaticMessageProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

};

#endif		// #ifndef APPLICATION_H
