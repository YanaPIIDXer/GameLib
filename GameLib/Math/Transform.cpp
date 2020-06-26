#include "Transform.h"

// コンストラクタ
Transform::Transform()
{
}

// 座標をセット
void Transform::SetLocation(float X, float Y, float Z)
{
	Location.SetTranslation(X, Y, Z);
}

// 回転をセット
void Transform::SetRotation(float Yaw, float Pitch, float Roll)
{
	Rotation.SetRotation(Yaw, Pitch, Roll);
}

// 移動
void Transform::Move(float X, float Y, float Z)
{
	Matrix Mat;
	Mat.SetTranslation(X, Y, Z);

	// 進行方向
	Mat = Rotation * Mat;

	// 移動
	Location = Mat * Location;
}

// ワールド軸を基準とした移動
void Transform::MoveWorld(float X, float Y, float Z)
{
	Location.Translate(X, Y, Z);
}

// 回転
void Transform::Rotate(float Yaw, float Pitch, float Roll)
{
	Rotation.Rotate(Yaw, Pitch, Roll);
}
