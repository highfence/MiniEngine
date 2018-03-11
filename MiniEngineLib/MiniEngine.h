#pragma once

namespace MiniEngineLib
{
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

		HINSTANCE m_hInst;
		INT m_nCmdShow;

	};
}