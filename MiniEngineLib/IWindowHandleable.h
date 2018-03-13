#pragma once
#include <combaseapi.h>

namespace MiniEngineLib
{
	/// Child Window�� �ڵ鸵�ϴ� Ŭ������ ���� �������̽�.
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
