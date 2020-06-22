#include "Transform.h"

// コンストラクタ
Transform::Transform()
{
	D3DXMatrixIdentity(&Location);
	D3DXMatrixIdentity(&Rotation);
}
