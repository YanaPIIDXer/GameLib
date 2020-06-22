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

private:

	// メッシュ
	// @TODO:本来はここには置かない。
	//		 この手のリソースは別の所にまとめておく。
	LPD3DXMESH pMesh;
};

#endif		// #ifndef TEAPOTCOMPONENT_H
