#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Matrix.h"

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

	/**
	 * @fn const Matrix GetLocationMatrix() const
	 * @brief �ʒu�s��擾
	 * @return �ʒu�s��
	 */
	const Matrix GetLocationMatrix() const { return Location; }

	/**
	 * @fn const Matrix GetRotationMatrix() const
	 * @brief ��]�s��擾
	 * @return ��]�s��
	 */
	const Matrix GetRotationMatrix() const { return Rotation; }

private:

	// �ʒu�s��
	Matrix Location;

	// ��]�s��
	Matrix Rotation;

};

#endif		// #ifndef TRANSFORM_H
