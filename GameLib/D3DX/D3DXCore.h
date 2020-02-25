#ifndef __D3DXCORE_H__
#define __D3DXCORE_H__

#include "d3dx9.h"

/**
 * @class D3DXCore
 * @brief DirectX�̃R�A�����B
 *        �f�o�C�X�̃C���X�^���X���B
 */
class D3DXCore
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	D3DXCore();

	/**
	 * @brief �f�X�g���N�^
	 */
	~D3DXCore();

	/**
	 * @fn bool Initialize();
	 * @brief ������
	 * @param[in] hWnd �E�B���h�E�n���h��
	 * @return ����������true��Ԃ��B
	 */
	bool Initialize(HWND hWnd);

private:
	
	// D3DX
	LPDIRECT3D9 pD3DX;

	// D3DX�f�o�C�X
	LPDIRECT3DDEVICE9 pDevice;

};

#endif		// #ifndef __D3DXCORE_H__
