#include "Scene.h"
#include "../Application/Application.h"
#include "../D3DX/Modules/D3DXRender.h"
#include "../Object/GameObject.h"

// �R���X�g���N�^
Scene::Scene()
	: pApplication(nullptr)
{
}

// �f�X�g���N�^
Scene::~Scene()
{
}

// �I�u�W�F�N�g�ǉ�
void Scene::AddObject(GameObject *pObject)
{
	pObject->Initialize(this);
	Objects.push_back(ObjectPtr(pObject));
}

// ���t���[���̏���
void Scene::Poll()
{
	for (auto It = Objects.begin(); It != Objects.end(); ++It)
	{
		if ((*It)->IsDestroyed())
		{
			It = Objects.erase(It);
		}
	}

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
	auto *pRender = pApplication->GetD3DXModule<D3DXRender>("Render");
	pRender->Begin();

	pRender->End();
}
