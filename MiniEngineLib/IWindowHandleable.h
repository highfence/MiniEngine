#pragma once
#include <combaseapi.h>

namespace MiniEngineLib
{
	/// Child Window를 핸들링하는 클래스를 위한 인터페이스.
	interface IChildWindowHandleable
	{
	public :
		virtual ~IChildWindowHandleable() { }

		virtual BOOL InitWindow(HINSTANCE hInst, HWND hWnd) = 0;
		virtual BOOL Create(INT width, INT height) = 0;
		virtual VOID MoveWindow() = 0;

		virtual BOOL IsInitialized() const = 0;

		virtual LRESULT MessageHandler(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) = 0;
	};
}
