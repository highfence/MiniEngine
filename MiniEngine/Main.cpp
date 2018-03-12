#include <Windows.h>
#include "../MiniEngineLib/MiniEngine.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE prevhInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	using namespace MiniEngineLib;

	MiniEngine engine;

	engine.InitEngine(hInstance, nCmdShow);

	engine.Run();

	return 0;
}