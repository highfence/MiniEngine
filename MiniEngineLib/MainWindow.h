#pragma once

namespace MiniEngineLib
{
	class EditWindow;
	class TextWindow;

	class MainWindow
	{
	public :
		MainWindow() = default;
		~MainWindow();

		BOOL InitWindow(HINSTANCE hInst, INT nCmdShow);
		BOOL Create(const INT width = 1200, const INT height = 800);

		VOID Update(const float deltaTime);

		BOOL IsInitialized() const { return _isWindowCreated; }
		HWND GetWinHandle() const { return _hWnd; }

		// For window message dispatcher
		INT_PTR CALLBACK MainWindowProc(HWND hWnd, UINT iMesshage, WPARAM wParam, LPARAM lParam);

	private :

		BOOL initializeChildWindows(HWND hWnd);

		HWND _hWnd;
		HINSTANCE _hInst;
		INT _cmdShow;
		LPCTSTR _appName = TEXT("MiniEngine v0.1");

		INT _windowWidth = 1200;
		INT _windowHeight = 800;

		BOOL _isWindowCreated = FALSE;

		EditWindow * _editWindow = nullptr;
		TextWindow * _textWindow = nullptr;
	};

	LRESULT CALLBACK WinMessageDispatcher(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	// Pointer directing MainWindow Instance (for windowMessageDispatcher)
	static MainWindow * mainWindowHandler = nullptr;
}