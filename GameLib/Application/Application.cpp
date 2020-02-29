#include "Application.h"
#include "../Game/Game.h"

// コンストラクタ
Application::Application(Game *pInGame, HINSTANCE pInInst, const std::string &InClassName)
	: pGame(pInGame)
	, pInst(pInInst)
	, ClassName(InClassName)
{
	WNDCLASSEX Wc = { sizeof(WNDCLASSEX), CS_CLASSDC, Application::StaticMessageProc, 0, 0, pInst, nullptr, nullptr, nullptr, nullptr, ClassName.c_str(), nullptr };
	RegisterClassEx(&Wc);
}

// 初期化
bool Application::Initialize(const std::string &WindowTitle, int X, int Y, int Width, int Height)
{
	HWND hWnd = CreateWindow(ClassName.c_str(), WindowTitle.c_str(), WS_OVERLAPPEDWINDOW, X, Y, Width, Height, nullptr, nullptr, pInst, this);
	SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
	ShowWindow(hWnd, SW_SHOWDEFAULT);

	if (!D3DX.Initialize(hWnd)) { return false; }

	return true;
}

// デストラクタ
Application::~Application()
{
	UnregisterClass(ClassName.c_str(), pInst);
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
		}
	}
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
