#include "Transform.h"

// �R���X�g���N�^
Transform::Transform()
{
	D3DXMatrixIdentity(&Location);
	D3DXMatrixIdentity(&Rotation);
}
