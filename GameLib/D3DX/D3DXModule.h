#ifndef D3DXMODULE_H
#define D3DXMODULE_H

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

#endif		// #ifndef D3DXMODULE_H
