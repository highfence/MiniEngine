#include "pch.h"
#include "MainWindow.h"

namespace MiniEngineLib
{
	MainWindow::MainWindow()
	{
	}

	MainWindow::~MainWindow()
	{
		DestroyWindow(_hWnd);
	}

	BOOL MainWindow::InitWindow(HINSTANCE hInst, INT nCmdShow)
	{
		_hInst = hInst;
		_cmdShow = nCmdShow;

		WNDCLASS wndClass;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndClass.hInstance = _hInst;
		wndClass.lpfnWndProc = WinMessageDispatcher;
		wndClass.lpszClassName = _appName;
		wndClass.lpszMenuName = NULL;
		wndClass.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClass(&wndClass))
			return false;

		// Static Instance Setting.
		mainWindowHandler = this;

		return true;
	}

	BOOL MainWindow::Create(INT width, INT height)
	{
		_windowWidth = width;
		_windowHeight = height;

		_hWnd = CreateWindow(
			_appName, _appName, WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, _windowWidth, _windowHeight,
			NULL, (HMENU)NULL, _hInst, NULL);

		if (_hWnd == NULL)
		{
			_isWindowCreated = FALSE;
			return _isWindowCreated;
		}

		ShowWindow(_hWnd, _cmdShow);

		_isWindowCreated = TRUE;
		return _isWindowCreated;
	}

	INT_PTR MainWindow::MainWindowProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		switch (iMessage)
		{
		// Child Window Initialize.
		case WM_CREATE :
		{
			break;
		}

		// If Window was moved
		case WM_SIZE :
		{
			if (wParam != SIZE_MINIMIZED)
				break;
		}
		}

		return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	}

	LRESULT CALLBACK WinMessageDispatcher(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		switch (iMessage)
		{
		case WM_DESTROY :
			PostQuitMessage(0);
			return 0;

		case WM_CLOSE :
			PostQuitMessage(0);
			return 0;

		default:
			return mainWindowHandler->MainWindowProc(hWnd, iMessage, wParam, lParam);
		}
	}
}
