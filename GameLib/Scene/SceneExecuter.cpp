#include "SceneExecuter.h"
#include "Scene.h"

// コンストラクタ
SceneExecuter::SceneExecuter()
	: pCurrentScene(nullptr)
{
}

// デストラクタ
SceneExecuter::~SceneExecuter()
{
}

// 毎フレーム実行する処理
void SceneExecuter::Poll()
{
	if (!pCurrentScene) { return; }
	pCurrentScene->Poll();
}
