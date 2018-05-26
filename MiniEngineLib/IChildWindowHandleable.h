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
		virtual BOOL Create(const INT width, const INT height, const INT positionX, const INT positionY) = 0;

		virtual BOOL IsInitialized() const = 0;
		virtual VOID ChangeSize(const INT width, const INT height, const INT positionX, const INT positionY) = 0;
	};
}
