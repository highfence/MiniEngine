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
		WndClass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
		WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		WndClass.hInstance = hInst;
		WndClass.lpfnWndProc = EditWindowProc;
		WndClass.lpszClassName = L"Edit Window";
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClass(&WndClass))
			return FALSE;

		EditWindowHandle = this;

		return TRUE;
	}

	BOOL EditWindow::Create(const INT width, const INT height, const INT positionX, const INT positionY)
	{
		_windowWidth  = width;
		_windowHeight = height;
		_positionX = positionX;
		_positionY = positionY;

		_hThisHandle = CreateWindow(TEXT("Edit Window"), NULL, WS_CHILD | WS_VISIBLE,
			_positionX, _positionY, _windowWidth, _windowHeight, _hParentHandle, (HMENU)0, _hInst, NULL);

		if (_hThisHandle == INVALID_HANDLE_VALUE || _hThisHandle == NULL)
			return FALSE;

		_isWindowCreated = TRUE;
		return TRUE;
	}

	VOID EditWindow::MoveWindow()
	{
		if (_hThisHandle != INVALID_HANDLE_VALUE)
			::MoveWindow(_hThisHandle, 800, 0, _windowWidth, _windowHeight, TRUE);
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
