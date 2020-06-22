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

// ������
void Scene::Initialize(Application *pInApplication)
{
	pApplication = pInApplication;
	CmpInitializer.pD3DXDevices = pApplication->GetD3DXDevices();
	for (auto pObj : Objects)
	{
		if (!pObj->IsInitialized())
		{
			pObj->Initialize(this);
		}
	}
}

// �I�u�W�F�N�g�ǉ�
void Scene::AddObject(GameObject *pObject)
{
	Objects.push_back(ObjectPtr(pObject));
	if (pApplication != nullptr)
	{
		pObject->Initialize(this);
	}
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
