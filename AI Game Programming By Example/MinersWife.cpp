#include "MinersWife.h"



MinersWife::MinersWife(int ID):BaseGameEntity(ID),
	m_Location(shack)
						
{
	m_pStateMachine = new StateMachine<MinersWife>(this);



}


MinersWife::~MinersWife()
{
}
