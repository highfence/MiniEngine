#include <Windows.h>
#include "../MiniEngineLib/MiniEngine.h"

INT APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE prevhInstance, LPSTR lpszCmdParam, INT nCmdShow)
{
	using namespace MiniEngineLib;

	MiniEngine engine;

	engine.InitEngine(hInstance, nCmdShow);

	engine.Run();

	return 0;
}