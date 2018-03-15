#pragma once

namespace MiniEngineLib
{
	class RenderWindow : public IChildWindowHandleable
	{
	public :
		RenderWindow();
		~RenderWindow();

		virtual BOOL InitWindow(HINSTANCE hInst, HWND hWnd) override;
		virtual BOOL Create(INT width, INT height) override;
		virtual VOID MoveWindow() override;

		virtual BOOL IsInitialized() const override { return _isWindowCreated; }

		VOID CommandProcedure(WPARAM wParam, LPARAM lParam);

	private :

		HINSTANCE _hInst;
		HWND _hThisHandle;
		HWND _hParentHandle;

		INT _windowWidth;
		INT _windowHeight;

		BOOL _isWindowCreated = FALSE;
	};

	static RenderWindow* RenderWindowHandle = nullptr;

	LRESULT CALLBACK RenderWindowProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
}
