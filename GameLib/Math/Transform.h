#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "d3dx9.h"

/**
 * @class Transform
 * @brief 姿勢
 */
class Transform
{
public:

	/**
	 * @brief コンストラクタ
	 */
	Transform();

	/**
	 * @brief デストラクタ
	 */
	~Transform() {}

private:

	// 位置行列
	D3DXMATRIX Location;

	// 回転行列
	D3DXMATRIX Rotation;

};

#endif		// #ifndef TRANSFORM_H
