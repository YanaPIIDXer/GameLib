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
	 * @fn void Initialize(GameObject *pInParent)
	 * @brief 初期化
	 * @param[in] pInParent 親
	 */
	void Initialize(GameObject *pInParent);

protected:

	/**
	 * @fn virtual void OnInitialize()
	 * @brief 初期化イベント
	 */
	virtual void OnInitialize() {}

private:

	// 親
	GameObject *pParent;

};

#endif		// #ifndef OBJECTCOMPONENT_H
