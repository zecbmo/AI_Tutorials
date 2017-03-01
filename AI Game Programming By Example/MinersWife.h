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

	void Update();

	StateMachine<MinersWife>* GetFSM() const { return m_pStateMachine; }

	location_type Location() const { return m_Location; }

	void ChangeLocation(const location_type loc) { m_Location = loc; }

};

