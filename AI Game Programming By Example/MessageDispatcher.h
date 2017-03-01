#pragma once

#include<set>
#include "Telegram.h"
#include "../Common/CrudeTimer.h"

class BaseGameEntity;

const double SEND_MSG_IMMEDIATELY = 0.0f;
const int NO_ADDITIONAL_INFO = 0;

#define Dispatch MessageDispatcher::Instance()


class MessageDispatcher
{

private:
	std::set<Telegram> PriorityQ;

	void Discharge(BaseGameEntity* pReciever, const Telegram& msg);


public:
	MessageDispatcher();
	~MessageDispatcher();


	static MessageDispatcher* Instance();

	void DispatchMsg(
		double  delay,
		int    sender,
		int    receiver,
		int    msg,
		void*  ExtraInfo);

	void DispatchDelayedMessages();



};

