#include "Scene.h"
#include "../Application/Application.h"

// �R���X�g���N�^
Scene::Scene()
	: pApplication(nullptr)
{
}

// �f�X�g���N�^
Scene::~Scene()
{
}

// ���t���[���̏���
void Scene::Poll()
{
	Render();
}

// ���̃V�[���ɑJ��
void Scene::SetNextScene(Scene *pNextScene)
{
	pApplication->SetNextScene(pNextScene);
}


// �`��
void Scene::Render()
{
	
}
