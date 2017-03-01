#pragma once

#include "../Common/State.h"

class MinersWife;

class WifeGlobalState : public State<MinersWife>
{
private:
	
	WifeGlobalState() {}

public:

	static WifeGlobalState* Instance();

	virtual void  Enter(MinersWife* wife) {};
	virtual void  Execute(MinersWife* wife);
	virtual void  Exit(MinersWife* wife) {};

};

class DoHouseWork : public State<MinersWife>
{

private:

	DoHouseWork() {}

public:
	static DoHouseWork* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

};

class VisitBathroom : public State<MinersWife>
{
private:

	VisitBathroom() {}

public:

	static VisitBathroom* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

};