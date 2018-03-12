#include "pch.h"
#include "MiniEngine.h"

namespace MiniEngineLib
{
	MiniEngine::MiniEngine()
	{
	}

	MiniEngine::~MiniEngine()
	{
	}

	void MiniEngine::InitEngine(HINSTANCE hInst, INT nCmdShow)
	{
		_hInst = hInst;
		_cmdShow = nCmdShow;
		
		_timer = std::make_unique<MiniTimer>();
		_timer->InitTimer();
		
		_mainWindow = std::make_unique<MainWindow>();
		_mainWindow->InitWindow(hInst, nCmdShow);

		_mainWindow->Create(1200, 800);
	}

	void MiniEngine::Run()
	{
		while (true)
		{

		}
	}
}