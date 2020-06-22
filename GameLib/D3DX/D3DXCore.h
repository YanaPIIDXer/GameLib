#ifndef D3DXCORE_H
#define D3DXCORE_H

#include "d3dx9.h"
#include "D3DXModule.h"
#include <memory>

/**
 * @struct D3DXDevices
 * @brief D3DX�f�o�C�X�\����
 */
struct D3DXDevices
{
	/**
	 * @brief D3DX
	 */
	LPDIRECT3D9 pD3DX;

	/**
	 * D3DX�f�o�C�X
	 */
	LPDIRECT3DDEVICE9 pDevice;
};

/**
 * @class D3DXCore
 * @brief DirectX�̃R�A�����B
 *        �f�o�C�X�̃C���X�^���X���B
 */
class D3DXCore : public ID3DXModule
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	D3DXCore();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~D3DXCore();

	/**
	 * @fn virtual const char *GetModuleName() const override
	 * @brief ���W���[�������擾
	 * @returns ���W���[����
	 */
	virtual const char *GetModuleName() const override { return "Core"; }

	/**
	 * @fn bool Initialize();
	 * @brief ������
	 * @param[in] hWnd �E�B���h�E�n���h��
	 * @return ����������true��Ԃ��B
	 */
	bool Initialize(HWND hWnd);

	/**
	 * @fn std::weak_ptr<D3DXDevices> GetDevices() const
	 * @brief �f�o�C�X�擾
	 * @return �f�o�C�X
	 */
	std::weak_ptr<D3DXDevices> GetDevices() const { return pDevices; }

private:
	
	// �f�o�C�X
	std::shared_ptr<D3DXDevices> pDevices;

	// ���
	void Release();

};

#endif		// #ifndef D3DXCORE_H
