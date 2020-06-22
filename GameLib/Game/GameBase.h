#ifndef GAMEBASE_H
#define GAMEBASE_H

/**
 * @class GameBase
 * @brief ゲーム制御基底クラス
 */
class GameBase
{
public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~GameBase() = 0;

	/**
	 * @fn void Poll()
	 * @brief 毎フレームの処理
	 */
	void Poll();

private:
};

#endif			// #ifndef GAMEBASEG_H
