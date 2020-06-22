#ifndef D3DXCORE_H
#define D3DXCORE_H

#include "D3DXModule.h"

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

	/**
	 * @fn D3DXDevicesPtr GetDevices() const
	 * @brief �f�o�C�X�擾
	 * @return �f�o�C�X
	 */
	D3DXDevicesPtr GetDevices() const { return pDevices; }

private:
	
	// �f�o�C�X
	std::shared_ptr<D3DXDevices> pDevices;

	// ���
	void Release();

};

#endif		// #ifndef D3DXCORE_H
