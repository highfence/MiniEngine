#pragma once

#include <memory>


namespace MiniEngineLib
{
	/// ���漱��.
	class MiniTimer;
	class MainWindow;

	///	MiniEngine class
	/// ���� Ŭ���� ��ü. 
	class MiniEngine
	{
	public :

		/// ���� Ŭ���� ������.
		MiniEngine();

		/// ���� Ŭ���� �Ҹ���.
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