#include "Application.h"

// メッセージプロシージャ
LRESULT WINAPI MessageProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
		case WM_DESTROY:

			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}


// コンストラクタ
Application::Application(HINSTANCE pInInst, const std::string &InClassName)
	: pInst(pInInst)
	, ClassName(InClassName)
{
	WNDCLASSEX Wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MessageProc, 0, 0, pInst, nullptr, nullptr, nullptr, nullptr, ClassName.c_str(), nullptr };
	RegisterClassEx(&Wc);
}

// 初期化
bool Application::Initialize(const std::string &WindowTitle, int X, int Y, int Width, int Height)
{
	HWND hWnd = CreateWindow(ClassName.c_str(), WindowTitle.c_str(), WS_OVERLAPPEDWINDOW, X, Y, Width, Height, nullptr, nullptr, pInst, nullptr);
	ShowWindow(hWnd, SW_SHOWDEFAULT);

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
