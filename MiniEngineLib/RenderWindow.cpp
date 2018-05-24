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
			return FALSE;

		RenderWindowHandle = this;

		return TRUE;
	}

	BOOL RenderWindow::Create(const INT width, const INT height, const INT positionX, const INT positionY)
	{
		_windowWidth = width;
		_windowHeight = height;

		_positionX = positionX;
		_positionY = positionY;

		_hThisHandle = CreateWindow(TEXT("Render Window"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
			_positionX, _positionY, _windowWidth, _windowHeight, _hParentHandle, (HMENU)0, _hInst, NULL);

		if (_hThisHandle == INVALID_HANDLE_VALUE)
			return FALSE;

		_isWindowCreated = TRUE;
		return TRUE;
	}

	VOID RenderWindow::MoveWindow()
	{
		if (_hThisHandle != INVALID_HANDLE_VALUE)
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

			break;
		}

		case WM_COMMAND:
		{

			break;
		}
		}

		return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
}
