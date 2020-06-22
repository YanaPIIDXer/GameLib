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

	/**
	 * @fn const D3DXMATRIX GetRotationMatrix() const
	 * @brief 位置行列取得
	 * @return 位置行列
	 */
	const D3DXMATRIX GetLocationMatrix() const { return Location; }

	/**
	 * @fn const D3DXMATRIX GetRotationMatrix() const
	 * @brief 回転行列取得
	 * @return 回転行列
	 */
	const D3DXMATRIX GetRotationMatrix() const { return Rotation; }

private:

	// 位置行列
	D3DXMATRIX Location;

	// 回転行列
	D3DXMATRIX Rotation;

};

#endif		// #ifndef TRANSFORM_H
