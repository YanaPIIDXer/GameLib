#ifndef SCENE_H
#define SCENE_H

/**
 * @class Scene
 * @brief シーンクラス。
 *        各シーンはこのクラスを派生させて実装する。
 */
class Scene
{
public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~Scene() = 0;

	/**
	 * @fn void Poll()
	 * @brief 毎フレームの処理
	 */
	void Poll();

protected:

private:
};

#endif		// #ifndef SCENE_H
