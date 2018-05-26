#pragma once

#include <memory>


namespace MiniEngineLib
{
	/// 전방선언.
	class MiniTimer;
	class MainWindow;

	///	MiniEngine class
	/// 엔진 클래스 본체. 
	class MiniEngine
	{
	public :

		/// 엔진 클래스 생성자.
		MiniEngine();

		/// 엔진 클래스 소멸자.
		~MiniEngine();

		void InitEngine(HINSTANCE hInst, INT nCmdShow);

		void Run();

	private :

		HINSTANCE _hInst;
		INT _cmdShow;
		MSG _msg;

		std::unique_ptr<MiniTimer> _timer;
		std::unique_ptr<MainWindow> _mainWindow;

	};

	extern HINSTANCE gEngineInstance;
}