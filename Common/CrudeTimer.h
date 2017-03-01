#pragma once



//this library must be included
#pragma comment(lib, "winmm.lib")

#include <windows.h>



#define Clock CrudeTimer::Instance()

class CrudeTimer
{
private:


	//set to the time (in seconds) when class is instantiated
	double m_dStartTime;

	//set the start time
	CrudeTimer() { m_dStartTime = timeGetTime() * 0.001; }

	//copy ctor and assignment should be private
	CrudeTimer(const CrudeTimer&);
	CrudeTimer& operator=(const CrudeTimer&);

public:

	static CrudeTimer* Instance();

	//returns how much time has elapsed since the timer was started
	double GetCurrentTime() { return timeGetTime() * 0.001 - m_dStartTime; }

};


