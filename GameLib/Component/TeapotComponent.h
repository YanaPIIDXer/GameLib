#ifndef TEAPOTCOMPONENT_H
#define TEAPOTCOMPONENT_H

#include "ObjectComponent.h"
#include "d3dx9.h"

/**
 * @class TeapotComponent
 * @brief ティーポットのメッシュコンポーネント
 */
class TeapotComponent : public ObjectComponent
{
public:

	/**
	 * @brief コンストラクタ
	 */
	TeapotComponent(GameObject *pInParent);

	/**
	 * @brief デストラクタ
	 */
	virtual ~TeapotComponent();

private:
};

#endif		// #ifndef TEAPOTCOMPONENT_H
