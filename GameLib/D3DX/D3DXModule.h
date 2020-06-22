#ifndef D3DXMODULE_H
#define D3DXMODULE_H

#include <memory>

/**
 * @class ID3DXModule
 * @brief D3DX�̋@�\���W���[���C���^�t�F�[�X
 */
class ID3DXModule
{
public:

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~ID3DXModule() {}

	/**
	 * @fn virtual const char *GetModuleName() const = 0
	 * @brief ���W���[�������擾
	 * @returns ���W���[����
	 */
	virtual const char *GetModuleName() const = 0;

};

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

#endif		// #ifndef D3DXMODULE_H
