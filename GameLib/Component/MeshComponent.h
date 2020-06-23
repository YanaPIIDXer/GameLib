#ifndef MESHCOMPONENT_H
#define MESHCOMPONENT_H

#include "ObjectComponent.h"
#include "d3dx9.h"

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
	 * @fn virtual void Render() override
	 * @brief �`��
	 */
	virtual void Render() override;

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
