#include "pch.h"
#include "RenderWindow.h"

namespace MiniEngineLib
{
	RenderWindow::RenderWindow() {}

	RenderWindow::~RenderWindow() {}

	BOOL RenderWindow::InitWindow(HINSTANCE hInst, HWND hWnd)
	{
		_hInst = hInst;
		_hParentHandle = hWnd;

		WNDCLASS WndClass;
		WndClass.cbClsExtra = 0;
		WndClass.cbWndExtra = 0;
		WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WndClass.hInstance = hInst;
		WndClass.lpfnWndProc = RenderWindowProc;
		WndClass.lpszClassName = L"Option Window";
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClass(&WndClass))
			return;

		RenderWindowHandle = this;
	}

	BOOL RenderWindow::Create(INT width, INT height)
	{
		_windowWidth = width;
		_windowHeight = height;

		_hThisHandle = CreateWindow(TEXT("Render Window"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
			0, 0, 0, 0, _hParentHandle, (HMENU)0, _hInst, NULL);
	}

	VOID RenderWindow::MoveWindow()
	{
		::MoveWindow(_hThisHandle, 0, 0, 800, 600, TRUE);
	}

	VOID RenderWindow::CommandProcedure(WPARAM wParam, LPARAM lParam)
	{
		return VOID();
	}

	LRESULT CALLBACK RenderWindowProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		switch (iMessage)
		{
		case WM_CREATE :
		{
		}

		case WM_COMMAND:
		{

		}

		}

		return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
}
