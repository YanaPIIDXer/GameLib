#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "d3dx9.h"

/**
 * @class Transform
 * @brief �p��
 */
class Transform
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	Transform();

	/**
	 * @brief �f�X�g���N�^
	 */
	~Transform() {}

private:

	// �ʒu�s��
	D3DXMATRIX Location;

	// ��]�s��
	D3DXMATRIX Rotation;

};

#endif		// #ifndef TRANSFORM_H
