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

public:		// オペレータオーバーロード

	/**
	 * @fn Matrix operator *(const Matrix &Arg)
	 * @brief 乗算
	 * @param[in] Arg 行列
	 * @return 乗算結果
	 */
	Matrix operator *(const Matrix &Arg) const
	{
		Matrix Value;
		Value.Mat = Mat * Arg.Mat;
		return Value;
	}

	/**
	 * @fn void operator *=(const Matrix &Arg)
	 * @brief 自身に乗算
	 * @param[in] Arg 行列
	 */
	void operator *=(const Matrix &Arg)
	{
		Mat *= Arg.Mat;
	}

private:

	// 行列
	D3DXMATRIX Mat;

};

#endif		// #ifndef MATRIX_H
