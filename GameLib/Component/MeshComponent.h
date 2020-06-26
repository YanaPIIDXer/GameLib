#ifndef MESHCOMPONENT_H
#define MESHCOMPONENT_H

#include "ObjectComponent.h"
#include "d3dx9.h"

class D3DXRender;

/**
 * @class MeshComponent
 * @brief メッシュ描画用コンポーネント
 */
class MeshComponent : public ObjectComponent
{
public:

	/**
	 * @brief コンストラクタ
	 */
	MeshComponent();

	/**
	 * @brief デストラクタ
	 */
	virtual ~MeshComponent();

	/**
	 * @fn virtual bool IsRenderComponent() const override
	 * @brief 描画コンポーネントか？
	 * @return 描画コンポーネントなのでtrue
	 */
	virtual bool IsRenderComponent() const override { return true; }

	/**
	 * @fn virtual void Render(D3DXRender) override
	 * @brief 描画
	 * @param[in] pRender 描画用インタフェース
	 */
	virtual void Render(D3DXRender *pRender) override;

protected:

	/**
	 * @fn void SetMesh(LPD3DXMESH pInMesh)
	 * @brief メッシュをセット
	 * @param[in] pInMesh メッシュ
	 */
	void SetMesh(LPD3DXMESH pInMesh);

private:

	// メッシュ
	// @TODO:本来はここには置かない。
	//		 この手のリソースは別の所にまとめておく。
	LPD3DXMESH pMesh;


	// 解放
	void Release();

};

#endif		// #ifndef MESHCOMPONENT_H
