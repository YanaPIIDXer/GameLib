#ifndef OBJECTCOMPONENT_H
#define OBJECTCOMPONENT_H

class GameObject;

#include "../D3DX/D3DXModule.h"

/**
 * @struct ComponentInitializer
 * @brief コンポーネント初期化用のオブジェクト
 */
struct ComponentInitializer
{
	/**
	 * @brief D3DXデバイス
	 */
	D3DXDevicesPtr pD3DXDevices;
};

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
	 * @fn void Initialize(GameObject *pInParent, const ComponentInitializer &Initializer)
	 * @brief 初期化
	 * @param[in] pInParent 親
	 * @param[in] Initializer 初期化オブジェクト
	 */
	void Initialize(GameObject *pInParent, const ComponentInitializer &Initializer);

	/**
	 * @fn bool IsInitialized() const
	 * @brief 初期化されているか？
	 * @return 初期化されていたらtrue
	 */
	bool IsInitialized() const { return (pParent != nullptr); }

	/**
	 * @fn virtual bool IsRenderComponent() const
	 * @brief 描画コンポーネントか？
	 * @return 描画コンポーネントならtrue
	 */
	virtual bool IsRenderComponent() const { return false; }

	/**
	 * @fn virtual void Update()
	 * @brief 更新
	 */
	virtual void Update() {}

	/**
	 * @fn virtual void Render()
	 * @brief 描画
	 */
	virtual void Render() {}

protected:

	/**
	 * @fn virtual void OnInitialize(const ComponentInitializer &Initializer)
	 * @brief 初期化イベント
	 * @param[in] Initializer 初期化オブジェクト
	 */
	virtual void OnInitialize(const ComponentInitializer &Initializer) {}

	/**
	 * @fn GameObject *GetParent() const
	 * @brief 親を取得
	 * @return 親
	 */
	GameObject *GetParent() const { return pParent; }

private:

	// 親
	GameObject *pParent;

};

#endif		// #ifndef OBJECTCOMPONENT_H
