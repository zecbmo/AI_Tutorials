#include "MinersWife.h"
#include "MinersWifeOwnedStates.h"


MinersWife::MinersWife(int ID):BaseGameEntity(ID),
	m_Location(shack)
						
{
	m_pStateMachine = new StateMachine<MinersWife>(this);

	m_pStateMachine->SetCurrentState(DoHouseWork::Instance());

	m_pStateMachine->SetGlobalState(WifeGlobalState::Instance());

}


MinersWife::~MinersWife()
{
	delete m_pStateMachine;
}

void MinersWife::Update()
{
	m_pStateMachine->Update();
}


