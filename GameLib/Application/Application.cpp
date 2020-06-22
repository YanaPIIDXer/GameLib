#include "Application.h"
#include "../Scene/Scene.h"

// コンストラクタ
Application::Application(HINSTANCE pInInst, const std::string &InClassName, Scene *pInitialScene)
	: pInst(pInInst)
	, ClassName(InClassName)
{
	if (pInitialScene)
	{
		SetNextScene(pInitialScene);
	}

	WNDCLASSEX Wc = { sizeof(WNDCLASSEX), CS_CLASSDC, Application::StaticMessageProc, 0, 0, pInst, nullptr, nullptr, nullptr, nullptr, ClassName.c_str(), nullptr };
	RegisterClassEx(&Wc);
}

// デストラクタ
Application::~Application()
{
	UnregisterClass(ClassName.c_str(), pInst);
}

// 初期化
bool Application::Initialize(const std::string &WindowTitle, int X, int Y, int Width, int Height)
{
	HWND hWnd = CreateWindow(ClassName.c_str(), WindowTitle.c_str(), WS_OVERLAPPEDWINDOW, X, Y, Width, Height, nullptr, nullptr, pInst, this);
	SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
	ShowWindow(hWnd, SW_SHOWDEFAULT);

	D3DXCore *pCore = new D3DXCore();
	if (!pCore->Initialize(hWnd))
	{
		delete pCore;
		return false;
	}

	AddD3DXModule(pCore);
	return true;
}

// メインループの実行
void Application::Run()
{
	MSG Msg;
	ZeroMemory(&Msg, sizeof(MSG));
	while (Msg.message != WM_QUIT)
	{
		if (PeekMessage(&Msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
			SceneExec.Poll();
		}
	}
}

// 次のシーンに遷移
void Application::SetNextScene(Scene *pScene)
{
	pScene->SetApplication(this);
	SceneExec.SetNextScene(pScene);
}

// D3DXモジュールを追加。
void Application::AddD3DXModule(ID3DXModule *pModule)
{
	D3DXModules[pModule->GetModuleName()] = std::unique_ptr<ID3DXModule>(pModule);
}


// メッセージプロシージャ
LRESULT Application::MessageProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
		case WM_DESTROY:

			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}


// メッセージプロシージャ
LRESULT CALLBACK Application::StaticMessageProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	Application *pApp = (Application *)(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	if (pApp == nullptr && Msg == WM_CREATE)
	{
		pApp = (Application *)(((LPCREATESTRUCT)lParam)->lpCreateParams);
	}
	
	if (pApp != nullptr)
	{
		return pApp->MessageProc(hWnd, Msg, wParam, lParam);
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}
