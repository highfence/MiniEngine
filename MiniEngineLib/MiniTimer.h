#pragma once

namespace MiniEngineLib
{
	/*
		필요한 기능만 구현된 타이머.
		초기화 시에 InitTimer를 콜해주고,
		Tick이 돌때마다 ProcessTime을,
		델타 타임이 필요할때 마다 GetElapsedTime을 콜해주면 된다.
	*/
	class MiniTimer
	{
	public :

		MiniTimer();
		~MiniTimer();

		void InitTimer();
		void ProcessTime();

		inline float GetElapsedTime() const
		{
			return m_ElapsedTime;
		}

	private :

		bool m_UseQPF;
		float m_ElapsedTime;
		LONGLONG m_QPFTicksPerSec;
		LONGLONG m_LastElapsedTime;
	};
}