#pragma once

namespace MiniEngineLib
{
	class MainWindow
	{
	public :

		MainWindow();
		
		~MainWindow();

		BOOL InitWindow(HINSTANCE hInst, INT nCmdShow);
		BOOL Create(INT width = 1200, INT height = 800);

		// For window message dispatcher
		INT_PTR CALLBACK MainWindowProc(HWND hWnd, UINT iMesshage, WPARAM wParam, LPARAM lParam);

		BOOL IsInitialized() const { return _isWindowCreated; }

		HWND GetWinHandle() const { return _hWnd; }

	private :

		HWND _hWnd;
		HINSTANCE _hInst;
		INT _cmdShow;
		LPCTSTR _appName = TEXT("MiniEngine v0.1");

		INT _windowWidth = 1200;
		INT _windowHeight = 800;

		BOOL _isWindowCreated = FALSE;
	};

	LRESULT CALLBACK WinMessageDispatcher(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	// Pointer directing MainWindow Instance (for windowMessageDispatcher)
	static MainWindow * mainWindowHandler = nullptr;
}