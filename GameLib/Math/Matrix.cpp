#include "Matrix.h"

// �R���X�g���N�^
Matrix::Matrix()
{
	D3DXMatrixIdentity(&Mat);
}

// ���W���Z�b�g
void Matrix::SetTranslation(float X, float Y, float Z)
{
	D3DXMatrixTranslation(&Mat, X, Y, Z);
}

// �ړ�
void Matrix::Translate(float X, float Y, float Z)
{
	D3DXMATRIX MoveMat;
	D3DXMatrixTranslation(&MoveMat, X, Y, Z);
	Mat *= MoveMat;
}

// ��]���Z�b�g
void Matrix::SetRotation(float Yaw, float Pitch, float Roll)
{
	D3DXMatrixRotationYawPitchRoll(&Mat, Yaw, Pitch, Roll);
}

// ��]
void Matrix::Rotate(float Yaw, float Pitch, float Roll)
{
	D3DXMATRIX RotateMat;
	D3DXMatrixRotationYawPitchRoll(&RotateMat, Yaw, Pitch, Roll);
	Mat *= RotateMat;
}
