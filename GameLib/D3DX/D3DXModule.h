#ifndef D3DXMODULE_H
#define D3DXMODULE_H

#include "d3dx9.h"
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
	 * @brief D3DX�f�o�C�X
	 */
	LPDIRECT3DDEVICE9 pDevice;
};

typedef std::weak_ptr<D3DXDevices> D3DXDevicesPtr;

/**
 * @class D3DXModule
 * @brief D3DX�̋@�\���W���[���C���^�t�F�[�X
 */
class D3DXModule
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	D3DXModule();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~D3DXModule();

	/**
	 * @fn virtual const char *GetModuleName() const = 0
	 * @brief ���W���[�������擾
	 * @returns ���W���[����
	 */
	virtual const char *GetModuleName() const = 0;

	/**
	 * @fn void SetDevices(D3DXDevicesPtr pInDevices)
	 * @brief �e�f�o�C�X�ւ̎Q�Ƃ��Z�b�g
	 * @param[in] pInDevices �f�o�C�X�ւ̎Q��
	 */
	void SetDevices(D3DXDevicesPtr pInDevices) { pDevices = pInDevices; }

protected:

	/**
	 * @fn LPDIRECT3D9 GetD3DX()
	 * @brief D3DX�擾
	 * @return D3DX
	 */
	LPDIRECT3D9 GetD3DX() { return pDevices.lock()->pD3DX; }

	/**
	 * @fn LPDIRECT3DDEVICE9 GetDevice()
	 * @brief D3DX�f�o�C�X�擾
	 * @return D3DX�f�o�C�X
	 */
	LPDIRECT3DDEVICE9 GetDevice() { return pDevices.lock()->pDevice; }

private:

	// �e�f�o�C�X�ւ̎Q��
	D3DXDevicesPtr pDevices;

};

#endif		// #ifndef D3DXMODULE_H
