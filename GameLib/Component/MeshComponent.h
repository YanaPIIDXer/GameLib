#ifndef MESHCOMPONENT_H
#define MESHCOMPONENT_H

#include "ObjectComponent.h"
#include "d3dx9.h"

class D3DXRender;

/**
 * @class MeshComponent
 * @brief ���b�V���`��p�R���|�[�l���g
 */
class MeshComponent : public ObjectComponent
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	MeshComponent();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~MeshComponent();

	/**
	 * @fn virtual bool IsRenderComponent() const override
	 * @brief �`��R���|�[�l���g���H
	 * @return �`��R���|�[�l���g�Ȃ̂�true
	 */
	virtual bool IsRenderComponent() const override { return true; }

	/**
	 * @fn virtual void Render(D3DXRender) override
	 * @brief �`��
	 * @param[in] pRender �`��p�C���^�t�F�[�X
	 */
	virtual void Render(D3DXRender *pRender) override;

protected:

	/**
	 * @fn void SetMesh(LPD3DXMESH pInMesh)
	 * @brief ���b�V�����Z�b�g
	 * @param[in] pInMesh ���b�V��
	 */
	void SetMesh(LPD3DXMESH pInMesh);

private:

	// ���b�V��
	// @TODO:�{���͂����ɂ͒u���Ȃ��B
	//		 ���̎�̃��\�[�X�͕ʂ̏��ɂ܂Ƃ߂Ă����B
	LPD3DXMESH pMesh;


	// ���
	void Release();

};

#endif		// #ifndef MESHCOMPONENT_H
