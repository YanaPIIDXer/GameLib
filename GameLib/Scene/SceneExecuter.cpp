#include "SceneExecuter.h"
#include "Scene.h"

// コンストラクタ
SceneExecuter::SceneExecuter()
	: pCurrentScene(nullptr)
	, pNextScene(nullptr)
{
}

// デストラクタ
SceneExecuter::~SceneExecuter()
{
}

// 毎フレーム実行する処理
void SceneExecuter::Poll()
{
	if (pNextScene)
	{
		pCurrentScene.swap(pNextScene);
		pNextScene.reset();
	}

	if (!pCurrentScene) { return; }
	pCurrentScene->Poll();
}

// 次のシーンに遷移
void SceneExecuter::SetNextScene(Scene *pScene)
{
	pNextScene.reset(pScene);
}
