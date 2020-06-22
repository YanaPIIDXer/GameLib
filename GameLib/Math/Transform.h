#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Matrix.h"

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
	 * @fn const Matrix GetLocationMatrix() const
	 * @brief 位置行列取得
	 * @return 位置行列
	 */
	const Matrix GetLocationMatrix() const { return Location; }

	/**
	 * @fn const Matrix GetRotationMatrix() const
	 * @brief 回転行列取得
	 * @return 回転行列
	 */
	const Matrix GetRotationMatrix() const { return Rotation; }

private:

	// 位置行列
	Matrix Location;

	// 回転行列
	Matrix Rotation;

};

#endif		// #ifndef TRANSFORM_H
