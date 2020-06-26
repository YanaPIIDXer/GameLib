#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Matrix.h"

/**
 * @class Transform
 * @brief p¨
 */
class Transform
{
public:

	/**
	 * @brief RXgN^
	 */
	Transform();

	/**
	 * @brief fXgN^
	 */
	~Transform() {}

	/**
	 * @fn void SetLocation(float X, float Y, float Z)
	 * @brief ÀWðZbg
	 * @param[in] X w
	 * @param[in] Y x
	 * @param[in] Z y
	 */
	void SetLocation(float X, float Y, float Z);

	/**
	 * @fn void SetRotation(float Yaw, float Pitch, float Roll)
	 * @brief ñ]ðZbg
	 * @param[in] Yaw [
	 * @param[in] Pitch sb`
	 * @param[in] Roll [
	 */
	void SetRotation(float Yaw, float Pitch, float Roll);

	/**
	 * @fn void World(float X, float Y, float Z)
	 * @brief Ú®
	 * @param[in] X w
	 * @param[in] Y x
	 * @param[in] Z y
	 */
	void Move(float X, float Y, float Z);

	/**
	 * @fn void MoveWorld(float X, float Y, float Z)
	 * @brief [h²ðîÉµ½Ú®
	 * @param[in] X w
	 * @param[in] Y x
	 * @param[in] Z y
	 */
	void MoveWorld(float X, float Y, float Z);

	/**
	 * @fn void Rotate(float Yaw, float Pitch, float Roll)
	 * @brief ñ]
	 * @param[in] Yaw [
	 * @param[in] Pitch sb`
	 * @param[in] Roll [
	 */
	void Rotate(float Yaw, float Pitch, float Roll);

	/**
	 * @fn D3DXMATRIX GetD3DXMatrix() const
	 * @brief D3DXMATRIXÅp¨ðæ¾
	 * @return D3DXMATRIX
	 */
	D3DXMATRIX GetD3DXMatrix() const
	{
		D3DXMATRIX Value = Rotation.Get();
		Value *= Location.Get();
		return Value;
	}

private:

	// Êusñ
	Matrix Location;

	// ñ]sñ
	Matrix Rotation;

};

#endif		// #ifndef TRANSFORM_H
