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
		virtual BOOL Create(const INT width, const INT height, const INT positionX, const INT positionY) = 0;

		virtual BOOL IsInitialized() const = 0;
		virtual VOID ChangeSize(const INT width, const INT height, const INT positionX, const INT positionY) = 0;
	};
}
