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
		_mainWindow->Create(1920, 1200);

		if (_mainWindow->IsInitialized() == FALSE)
			MessageBox(_mainWindow->GetWinHandle(), TEXT("Engine Initialize failed."), NULL, NULL);
	}

	void MiniEngine::Run()
	{
		const float frameTime = 1.f / 60.f;
		static float accTime = 0.f;
		_timer->ProcessTime();

		while (true)
		{
			accTime += _timer->GetElapsedTime();
			if (PeekMessage(&_msg, NULL, 0, 0, PM_REMOVE))
			{
				if (_msg.message == WM_QUIT)
					break;

				TranslateMessage(&_msg);
				DispatchMessage(&_msg);
			}
			else
			{
				if (accTime >= frameTime)
				{
					_mainWindow.get()->Update(accTime);
					accTime = 0.f;
				}
			}
		}
	}
}