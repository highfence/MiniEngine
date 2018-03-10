#pragma once

namespace MiniEngine
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

		void InitEngine();

		void Run();

	private :
	};
}