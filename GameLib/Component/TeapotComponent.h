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
	TeapotComponent(GameObject *pInParent);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~TeapotComponent();

private:
};

#endif		// #ifndef TEAPOTCOMPONENT_H
