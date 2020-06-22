#ifndef MATRIX_H
#define MATRIX_H

#include "d3dx9.h"

/**
 * @class Matrix
 * @brief 行列クラス。
 *        実態はD3DXMATRIXのラッパー。
 */
class Matrix
{
public:

	/**
	 * @brief コンストラクタ
	 */
	Matrix();

	/**
	 * @brief デストラクタ
	 */
	~Matrix() {}

	/**
	 * @fn void ToIdentity()
	 * @brief 単位行列にする。
	 */
	void ToIdentity() { D3DXMatrixIdentity(&Mat); }

	/**
	 * @fn const D3DXMATRIX Get() const
	 * @brief 取得
	 * @return 行列
	 */
	const D3DXMATRIX Get() const { return Mat; }

private:

	// 行列
	D3DXMATRIX Mat;

};

#endif		// #ifndef MATRIX_H
