#ifndef TEAPOTCOMPONENT_H
#define TEAPOTCOMPONENT_H

#include "MeshComponent.h"

/**
 * @class TeapotComponent
 * @brief �e�B�[�|�b�g�̃��b�V���R���|�[�l���g
 */
class TeapotComponent : public MeshComponent
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

protected:

	/**
	 * @fn virtual void OnInitialize(const ComponentInitializer &Initializer) override
	 * @brief �������C�x���g
	 * @param[in] Initializer �������I�u�W�F�N�g
	 */
	virtual void OnInitialize(const ComponentInitializer &Initializer) override;

};

#endif		// #ifndef TEAPOTCOMPONENT_H
