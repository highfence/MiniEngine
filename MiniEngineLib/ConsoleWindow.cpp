
#include "pch.h"
#include "ConsoleWindow.h"

namespace MiniEngineLib
{
	ConsoleWindow::ConsoleWindow() { }

	ConsoleWindow::~ConsoleWindow() { }

	BOOL ConsoleWindow::InitWindow(HINSTANCE hInst, HWND hWnd)
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
		WndClass.lpfnWndProc = TextWindowProc;
		WndClass.lpszClassName = L"Text Window";
		WndClass.lpszMenuName = NULL;
		WndClass.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClass(&WndClass))
			return FALSE;

		TextWindowHandle = this;

		return TRUE;
	}

	BOOL ConsoleWindow::Create(const INT width, const INT height, const INT positionX, const INT positionY)
	{
		_windowWidth = width;
		_windowHeight = height;

		_positionX = positionX;
		_positionY = positionY;

		_hThisHandle = CreateWindow(TEXT("Text Window"), NULL, WS_CHILD | WS_VISIBLE,
			_positionX, _positionY, _windowWidth, _windowHeight, _hParentHandle, (HMENU)0, _hInst, NULL);

		if (_hThisHandle == INVALID_HANDLE_VALUE || _hThisHandle == NULL)
			return FALSE;

		_isWindowCreated = TRUE;
		return TRUE;
	}

	VOID ConsoleWindow::ChangeSize(const INT width, const INT height, const INT positionX, const INT positionY)
	{
		if (_hThisHandle != INVALID_HANDLE_VALUE && _hThisHandle != NULL)
			::MoveWindow(_hThisHandle, positionX, positionY, width, height, TRUE);
	}

	LRESULT CALLBACK TextWindowProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{


		return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
}
