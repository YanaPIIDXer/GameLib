#ifndef OBJECTCOMPONENT_H
#define OBJECTCOMPONENT_H

class GameObject;

/**
 * @class ObjectComponent
 * @brief オブジェクトに貼り付けるコンポーネント
 */
class ObjectComponent
{
public:

	/**
	 * @brief コンストラクタ
	 */
	ObjectComponent();

	/**
	 * @brief デストラクタ
	 */
	virtual ~ObjectComponent() = 0;

	/**
	 * @fn void SetParent(GameObject *pInParent)
	 * @brief 親を設定
	 * @param[in] pInParent 親
	 */
	void SetParent(GameObject *pInParent) { pParent = pInParent; }

private:

	// 親
	GameObject *pParent;

};

#endif		// #ifndef OBJECTCOMPONENT_H
