#include "Matrix.h"

// コンストラクタ
Matrix::Matrix()
{
	D3DXMatrixIdentity(&Mat);
}

// 座標をセット
void Matrix::SetTranslation(float X, float Y, float Z)
{
	D3DXMatrixTranslation(&Mat, X, Y, Z);
}

// 移動
void Matrix::Translate(float X, float Y, float Z)
{
	D3DXMATRIX MoveMat;
	D3DXMatrixTranslation(&MoveMat, X, Y, Z);
	Mat *= MoveMat;
}

// 回転をセット
void Matrix::SetRotation(float Yaw, float Pitch, float Roll)
{
	D3DXMatrixRotationYawPitchRoll(&Mat, Yaw, Pitch, Roll);
}

// 回転
void Matrix::Rotate(float Yaw, float Pitch, float Roll)
{
	D3DXMATRIX RotateMat;
	D3DXMatrixRotationYawPitchRoll(&RotateMat, Yaw, Pitch, Roll);
	Mat *= RotateMat;
}
