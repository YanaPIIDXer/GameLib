#include "SceneExecuter.h"
#include "Scene.h"

// �R���X�g���N�^
SceneExecuter::SceneExecuter()
	: pCurrentScene(nullptr)
	, pNextScene(nullptr)
{
}

// �f�X�g���N�^
SceneExecuter::~SceneExecuter()
{
}

// ���t���[�����s���鏈��
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

// ���̃V�[���ɑJ��
void SceneExecuter::SetNextScene(Scene *pScene)
{
	pNextScene.reset(pScene);
}
