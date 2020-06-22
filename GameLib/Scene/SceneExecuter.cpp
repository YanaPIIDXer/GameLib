#include "SceneExecuter.h"
#include "Scene.h"

// �R���X�g���N�^
SceneExecuter::SceneExecuter()
	: pCurrentScene(nullptr)
{
}

// �f�X�g���N�^
SceneExecuter::~SceneExecuter()
{
}

// ���t���[�����s���鏈��
void SceneExecuter::Poll()
{
	if (!pCurrentScene) { return; }
	pCurrentScene->Poll();
}
