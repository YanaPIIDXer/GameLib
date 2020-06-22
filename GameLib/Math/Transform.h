#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "d3dx9.h"

/**
 * @class Transform
 * @brief �p��
 *        @TODO:����D3DXMATRIX���g���Ă邪�A
 *		        ���b�p�[�N���X��������������B
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

	/**
	 * @fn const D3DXMATRIX GetRotationMatrix() const
	 * @brief �ʒu�s��擾
	 * @return �ʒu�s��
	 */
	const D3DXMATRIX GetLocationMatrix() const { return Location; }

	/**
	 * @fn const D3DXMATRIX GetRotationMatrix() const
	 * @brief ��]�s��擾
	 * @return ��]�s��
	 */
	const D3DXMATRIX GetRotationMatrix() const { return Rotation; }

private:

	// �ʒu�s��
	D3DXMATRIX Location;

	// ��]�s��
	D3DXMATRIX Rotation;

};

#endif		// #ifndef TRANSFORM_H
