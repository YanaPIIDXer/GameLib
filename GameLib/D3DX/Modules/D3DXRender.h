#ifndef D3DXRENDER_H
#define D3DXRENDER_H

#include "../D3DXModule.h"

/**
 * @class D3DXRender
 * @brief �`�惂�W���[��
 */
class D3DXRender : public D3DXModule
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	D3DXRender();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~D3DXRender();

	/**
	 * @fn virtual const char *GetModuleName() const override
	 * @brief ���W���[�������擾
	 * @returns ���W���[����
	 */
	virtual const char *GetModuleName() const override { return "Render"; }

	/**
	 * @fn void Begin()
	 * @brief �`��J�n
	 */
	void Begin();

	/**
	 * @fn void End()
	 * @brief �`��I��
	 */
	void End();

	/**
	 * @fn void SetClearColor(D3DCOLOR InClearColor)
	 * @brief �N���A���̓h��ׂ��F��ݒ�
	 * @param[in] R ��
	 * @param[in] G ��
	 * @param[in] B ��
	 */
	void SetClearColor(BYTE R, BYTE G, BYTE B) { ClearColor = D3DCOLOR_XRGB(R, G, B); }

private:

	// �`�撆�H
	bool bIsRendering;

	// �N���A���̓h��ׂ��F
	D3DCOLOR ClearColor;

};

#endif		// #ifndef D3DXRENDER_H
