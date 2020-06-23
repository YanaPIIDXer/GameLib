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
	 * @fn void SetLocation(float X, float Y, float Z)
	 * @brief 座標をセット
	 * @param[in] X Ｘ
	 * @param[in] Y Ｙ
	 * @param[in] Z Ｚ
	 */
	void SetLocation(float X, float Y, float Z);

	/**
	 * @fn void SetRotation(float Yaw, float Pitch, float Roll)
	 * @brief 回転をセット
	 * @param[in] Yaw ヨー
	 * @param[in] Pitch ピッチ
	 * @param[in] Roll ロール
	 */
	void SetRotation(float Yaw, float Pitch, float Roll);

	/**
	 * @fn D3DXMATRIX GetD3DXMatrix() const
	 * @brief D3DXMATRIXで姿勢を取得
	 * @return D3DXMATRIX
	 */
	D3DXMATRIX GetD3DXMatrix() const
	{
		D3DXMATRIX Value = Rotation.Get();
		Value *= Location.Get();
		return Value;
	}

private:

	// 位置行列
	Matrix Location;

	// 回転行列
	Matrix Rotation;

};

#endif		// #ifndef TRANSFORM_H
