#ifndef OBJECTCOMPONENT_H
#define OBJECTCOMPONENT_H

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

private:

};

#endif		// #ifndef OBJECTCOMPONENT_H
