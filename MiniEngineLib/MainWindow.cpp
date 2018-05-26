#include "pch.h"
#include "MainWindow.h"

namespace MiniEngineLib
{
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
		wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
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

	BOOL MainWindow::Create(const INT width, const INT height)
	{
		_windowWidth = width;
		_windowHeight = height;

		_hWnd = CreateWindow(
			_appName, _appName, WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, _windowWidth, _windowHeight,
			NULL, (HMENU)NULL, _hInst, NULL);

		if (_hWnd == NULL || _hWnd == INVALID_HANDLE_VALUE)
		{
			_isWindowCreated = FALSE;
			return _isWindowCreated;
		}

		ShowWindow(_hWnd, _cmdShow);
		_isWindowCreated = TRUE;

		return _isWindowCreated;
	}

	VOID MainWindow::Update(const float deltaTime)
	{

	}

	INT_PTR MainWindow::MainWindowProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
	{
		switch (iMessage)
		{
		// Child Window Initialize.
		case WM_CREATE :
		{
			initializeChildWindows(hWnd);

			break;
		}

		// If Window was moved
		case WM_SIZE :
		{
			//if (wParam != SIZE_MINIMIZED)
			//	break;

			static RECT rt;
			GetClientRect(hWnd, &rt);
			InvalidateRect(hWnd, NULL, TRUE);

			_windowWidth = rt.right - rt.left;
			_windowHeight = rt.bottom - rt.top;

			changeChildWindowsSize(_windowWidth, _windowHeight);
			break;
		}
		}

		return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	}

	BOOL MainWindow::initializeChildWindows(HWND hWnd)
	{
		BOOL isInitializedWell = FALSE;

		Vector<int> divPosition(_windowWidth * 0.8f, _windowHeight * 0.75f);

		_renderWindow = new RenderWindow();
		_renderWindow->InitWindow(_hInst, hWnd);
		_renderWindow->Create(divPosition._x, divPosition._y, 0, 0);

		_editWindow = new EditWindow();
		_editWindow->InitWindow(_hInst, hWnd);
		_editWindow->Create(_windowWidth - divPosition._x, _windowHeight, divPosition._x, 0);

		_consoleWindow = new ConsoleWindow();
		_consoleWindow->InitWindow(_hInst, hWnd);
		_consoleWindow->Create(divPosition._x, _windowHeight - divPosition._y, 0, divPosition._y);

		changeChildWindowsSize(_windowWidth, _windowHeight);

		return isInitializedWell;
	}

	BOOL MainWindow::changeChildWindowsSize(const INT clientWidth, const INT clientHeight)
	{
		Vector<int> divPosition(clientWidth * 0.8f, clientHeight * 0.75f);

		if (_renderWindow != nullptr)
			_renderWindow->ChangeSize(divPosition._x, divPosition._y, 0, 0);

		if (_editWindow != nullptr)
			_editWindow->ChangeSize(clientWidth - divPosition._x, clientHeight, divPosition._x, 0);

		if (_consoleWindow != nullptr)
			_consoleWindow->ChangeSize(divPosition._x, clientHeight - divPosition._y, 0, divPosition._y);

		return TRUE;
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
