#include "Miner.h"
#include "State.h"


Miner::Miner(int ID) :BaseGameEntity(ID),
					m_Location(shack),
					m_iGoldCarried(0),
					m_iMoneyInBank(0),
					m_iThirst(0),
					m_iFatigue(0),
					m_pCurrentState(GoHomeAndSleepTilRested::Instance())
{

}


void Miner::Update()
{
	m_iThirst += 1;

	if (m_pCurrentState)
	{
		m_pCurrentState->Execute(this);
	}
}

void Miner::ChangeState(State * pNewState)
{
	//Make Sure both states are valid
	assert(m_pCurrentState && pNewState);

	//Exiting method
	m_pCurrentState->Exit(this);

	//change to new state
	m_pCurrentState = pNewState;

	//Call entry method

	m_pCurrentState->Enter(this);

}

void Miner::AddToGoldCarried(const int val)
{
	m_iGoldCarried += val;

	if (m_iGoldCarried < 0)
	{
		m_iGoldCarried = 0;
	}
}

bool Miner::Fatigued() const
{
	if (m_iFatigue > TirednessThreshold)
	{
		return true;
	}

	return false;
}

void Miner::AddToWealth(const int val)
{
	m_iMoneyInBank += val;

	if (m_iMoneyInBank < 0)
	{
		m_iMoneyInBank = 0;
	}
}

bool Miner::Thirsty() const
{
	if (m_iThirst >= ThirstLevel) 
	{
		return true; 
	}

	return false;
}
