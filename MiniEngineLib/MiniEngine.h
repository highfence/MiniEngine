#pragma once

namespace MiniEngineLib
{
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

		HINSTANCE m_hInst;
		INT m_nCmdShow;

	};
}