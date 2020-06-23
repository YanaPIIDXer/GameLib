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
	 * @fn void SetLocation(float X, float Y, float Z)
	 * @brief ���W���Z�b�g
	 * @param[in] X �w
	 * @param[in] Y �x
	 * @param[in] Z �y
	 */
	void SetLocation(float X, float Y, float Z);

	/**
	 * @fn void SetRotation(float Yaw, float Pitch, float Roll)
	 * @brief ��]���Z�b�g
	 * @param[in] Yaw ���[
	 * @param[in] Pitch �s�b�`
	 * @param[in] Roll ���[��
	 */
	void SetRotation(float Yaw, float Pitch, float Roll);

	/**
	 * @fn D3DXMATRIX GetD3DXMatrix() const
	 * @brief D3DXMATRIX�Ŏp�����擾
	 * @return D3DXMATRIX
	 */
	D3DXMATRIX GetD3DXMatrix() const
	{
		D3DXMATRIX Value = Rotation.Get();
		Value *= Location.Get();
		return Value;
	}

private:

	// �ʒu�s��
	Matrix Location;

	// ��]�s��
	Matrix Rotation;

};

#endif		// #ifndef TRANSFORM_H
