#pragma once

#include <iostream>
#include <math.h>

struct Telegram
{
	int Sender;

	int Receiver;

	int Msg;

	double DispatchTime;

	void* ExtraInfo;


	Telegram() :DispatchTime(-1),
		Sender(-1),
		Receiver(-1),
		Msg(-1)
	{}


	Telegram(double time, int sender, int reciever, int msg, void* info = NULL)
		:DispatchTime(time),
		Sender(sender),
		Receiver(reciever),
		Msg(msg),
		ExtraInfo(info)
	{	
	}
};

const double SmallestDelay = 0.25;

inline bool operator==(const Telegram& t1, const Telegram t2)
{
	return (fabs(t1.DispatchTime - t2.DispatchTime) < SmallestDelay) &&
		(t1.Sender == t2.Sender) &&
		(t1.Receiver == t2.Receiver) &&
		(t1.Msg == t2.Msg);
}

inline bool operator<(const Telegram& t1, const Telegram& t2)
{
	if (t1 == t2)
	{
		return false;
	}

	else
	{
		return  (t1.DispatchTime < t2.DispatchTime);
	}
}

inline std::ostream& operator<<(std::ostream& os, const Telegram& t)
{
	os << "time: " << t.DispatchTime << "  Sender: " << t.Sender
		<< "   Receiver: " << t.Receiver << "   Msg: " << t.Msg;

	return os;
}

template <class T>
inline T DereferenceToType(void* p)
{
	return *(T*)(p);
}
