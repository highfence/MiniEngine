#pragma once

namespace MiniEngineLib
{
	class MiniTimer
	{
	public :

		MiniTimer();
		~MiniTimer();

		void Init();
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