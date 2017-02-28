#pragma once
#include "BaseGameEntity.h"
#include "../Common/StateMachine.h"
#include "Miner.h"

class MinersWife :
	public BaseGameEntity
{
private:
	StateMachine<MinersWife>* m_pStateMachine;

	location_type m_Location;


public:
	MinersWife(int ID);
	~MinersWife();
};

