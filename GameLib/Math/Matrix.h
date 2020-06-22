#ifndef MATRIX_H
#define MATRIX_H

#include "d3dx9.h"

/**
 * @class Matrix
 * @brief �s��N���X�B
 *        ���Ԃ�D3DXMATRIX�̃��b�p�[�B
 */
class Matrix
{
public:

	/**
	 * @brief �R���X�g���N�^
	 */
	Matrix();

	/**
	 * @brief �f�X�g���N�^
	 */
	~Matrix() {}

	/**
	 * @fn void ToIdentity()
	 * @brief �P�ʍs��ɂ���B
	 */
	void ToIdentity() { D3DXMatrixIdentity(&Mat); }

	/**
	 * @fn void SetTranslation(float X, float Y, float Z)
	 * @brief ���W���Z�b�g
	 * @param[in] X �w
	 * @param[in] Y �x
	 * @param[in] Z �y
	 */
	void SetTranslation(float X, float Y, float Z);

	/**
	 * @fn void Translate(float X, float Y, float Z)
	 * @brief �ړ�
	 * @param[in] X �w
	 * @param[in] Y �x
	 * @param[in] Z �y
	 */
	void Translate(float X, float Y, float Z);

	/**
	 * @fn void SetRotation(float Yaw, float Pitch, float Roll)
	 * @brief ��]���Z�b�g
	 * @param[in] Yaw ���[
	 * @param[in] Pitch �s�b�`
	 * @param[in] Roll ���[��
	 */
	void SetRotation(float Yaw, float Pitch, float Roll);

	/**
	 * @fn void Rotate(float Yaw, float Pitch, float Roll)
	 * @brief ��]
	 * @param[in] Yaw ���[
	 * @param[in] Pitch �s�b�`
	 * @param[in] Roll ���[��
	 */
	void Rotate(float Yaw, float Pitch, float Roll);

	/**
	 * @fn const D3DXMATRIX Get() const
	 * @brief �擾
	 * @return �s��
	 */
	const D3DXMATRIX Get() const { return Mat; }

public:		// �I�y���[�^�I�[�o�[���[�h

	/**
	 * @fn Matrix operator *(const Matrix &Arg)
	 * @brief ��Z
	 * @param[in] Arg �s��
	 * @return ��Z����
	 */
	Matrix operator *(const Matrix &Arg) const
	{
		Matrix Value;
		Value.Mat = Mat * Arg.Mat;
		return Value;
	}

	/**
	 * @fn void operator *=(const Matrix &Arg)
	 * @brief ���g�ɏ�Z
	 * @param[in] Arg �s��
	 */
	void operator *=(const Matrix &Arg)
	{
		Mat *= Arg.Mat;
	}

private:

	// �s��
	D3DXMATRIX Mat;

};

#endif		// #ifndef MATRIX_H
