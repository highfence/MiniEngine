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

		virtual BOOL IsInitialized() const override;

		virtual LRESULT MessageHandler(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) override;

	private :
	};
}
