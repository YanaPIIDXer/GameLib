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
void Transform::MoveWorld(float X, float Y, float Z)
{
	Location.Translate(X, Y, Z);
}
