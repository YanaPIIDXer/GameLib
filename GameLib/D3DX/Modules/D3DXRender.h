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

private:

	// �`�撆�H
	bool bIsRendering;

};

#endif		// #ifndef D3DXRENDER_H
