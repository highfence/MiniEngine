#include "pch.h"
#include "EditWindow.h"


namespace MiniEngineLib
{
	EditWindow::EditWindow() {}

	EditWindow::~EditWindow() {}

	BOOL EditWindow::InitWindow(HINSTANCE hInst, HWND hWnd)
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
		WndClass.lpfnWndProc = EditWindowProc;
		WndClass.lpszClassName = L"Option Window";
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClass(&WndClass))
			return;

		EditWindowHandle = this;
	}

	BOOL EditWindow::Create(INT width, INT height)
	{
		_windowWidth = width;
		_windowHeight = height;

		_hThisHandle = CreateWindow(TEXT("Option Window"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
			0, 0, 0, 0, _hParentHandle, (HMENU)0, _hInst, NULL);
	}

	VOID EditWindow::MoveWindow()
	{
		::MoveWindow(_hThisHandle, 800, 0, 300, 600, TRUE);
	}

	VOID EditWindow::CreateChildWindows(HWND hWnd)
	{
		return VOID();
	}

	VOID EditWindow::CommandProcedure(WPARAM wParam, LPARAM lParam)
	{
		return VOID();
	}

	LRESULT CALLBACK EditWindowProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		switch (iMessage)
		{
		case WM_CREATE :
		{
			EditWindowHandle->CreateChildWindows(hWnd);
			break;
		}

		case WM_COMMAND :
		{
			EditWindowHandle->CommandProcedure(wParam, lParam);
			break;
		}
		}

		return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
}
