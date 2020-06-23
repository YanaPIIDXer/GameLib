#ifndef TEAPOTCOMPONENT_H
#define TEAPOTCOMPONENT_H

#include "MeshComponent.h"

/**
 * @class TeapotComponent
 * @brief ティーポットのメッシュコンポーネント
 */
class TeapotComponent : public MeshComponent
{
public:

	/**
	 * @brief コンストラクタ
	 */
	TeapotComponent();

	/**
	 * @brief デストラクタ
	 */
	virtual ~TeapotComponent();

protected:

	/**
	 * @fn virtual void OnInitialize(const ComponentInitializer &Initializer) override
	 * @brief 初期化イベント
	 * @param[in] Initializer 初期化オブジェクト
	 */
	virtual void OnInitialize(const ComponentInitializer &Initializer) override;

};

#endif		// #ifndef TEAPOTCOMPONENT_H
