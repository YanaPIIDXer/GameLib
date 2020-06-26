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

// �ړ�
void Transform::Move(float X, float Y, float Z)
{
	Matrix Mat;
	Mat.SetTranslation(X, Y, Z);

	// �i�s����
	Mat = Rotation * Mat;

	// �ړ�
	Location = Mat * Location;
}

// ���[���h������Ƃ����ړ�
void Transform::MoveWorld(float X, float Y, float Z)
{
	Location.Translate(X, Y, Z);
}

// ��]
void Transform::Rotate(float Yaw, float Pitch, float Roll)
{
	Rotation.Rotate(Yaw, Pitch, Roll);
}
