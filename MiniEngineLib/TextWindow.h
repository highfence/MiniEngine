#pragma once

namespace MiniEngineLib
{
	class TextWindow : public IChildWindowHandleable
	{
	public :
		TextWindow();
		~TextWindow();

		virtual BOOL InitWindow(HINSTANCE hInst, HWND hWnd) override;

		virtual BOOL Create(const INT width, const INT height, const INT positionX, const INT positionY) override;
		virtual VOID MoveWindow() override;

		virtual BOOL IsInitialized() const override { return _isWindowCreated; };

	private :

		HINSTANCE _hInst;
		HWND _hParentHandle;
		HWND _hThisHandle;

		INT _windowWidth;
		INT _windowHeight;
		INT _positionX;
		INT _positionY;

		BOOL _isWindowCreated = FALSE;
	};

	static TextWindow* TextWindowHandle = nullptr;

	LRESULT CALLBACK TextWindowProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
}