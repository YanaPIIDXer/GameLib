#include "Transform.h"

// �R���X�g���N�^
Transform::Transform()
{
}

// ���W���Z�b�g
void Transform::SetLocation(float X, float Y, float Z)
{
	Location.SetTranslation(X, Y, Z);
}

// ��]���Z�b�g
void Transform::SetRotation(float Yaw, float Pitch, float Roll)
{
	Rotation.SetRotation(Yaw, Pitch, Roll);
}
