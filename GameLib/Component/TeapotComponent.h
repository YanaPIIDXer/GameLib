#ifndef TEAPOTCOMPONENT_H
#define TEAPOTCOMPONENT_H

#include "ObjectComponent.h"
#include "d3dx9.h"

/**
 * @class TeapotComponent
 * @brief �e�B�[�|�b�g�̃��b�V���R���|�[�l���g
 */
class TeapotComponent : public ObjectComponent
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	TeapotComponent();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~TeapotComponent();

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
	 * @fn virtual void OnInitialize(const ComponentInitializer &Initializer) override
	 * @brief �������C�x���g
	 * @param[in] Initializer �������I�u�W�F�N�g
	 */
	virtual void OnInitialize(const ComponentInitializer &Initializer) override;

private:

	// ���b�V��
	// @TODO:�{���͂����ɂ͒u���Ȃ��B
	//		 ���̎�̃��\�[�X�͕ʂ̏��ɂ܂Ƃ߂Ă����B
	LPD3DXMESH pMesh;
};

#endif		// #ifndef TEAPOTCOMPONENT_H
