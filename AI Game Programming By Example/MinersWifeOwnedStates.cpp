#include "MinersWifeOwnedStates.h"
#include "../Common/Utils.h"
#include "MinersWife.h"
#include "EntityNames.h"

////////////////////////////////////////////////////// Global

WifeGlobalState * WifeGlobalState::Instance()
{	
	static WifeGlobalState instance;

	return &instance;
}

void WifeGlobalState::Execute(MinersWife * wife)
{
	if (RandFloat() < 0.1)
	{
		wife->GetFSM()->ChangeState(VisitBathroom::Instance());
	}

}

////////////////////////////////////////////////////// House work state

DoHouseWork * DoHouseWork::Instance()
{
	static DoHouseWork instance;

	return &instance;
}

void DoHouseWork::Enter(MinersWife * wife)
{
}

void DoHouseWork::Execute(MinersWife * wife)
{
	switch (RandInt(0,2))
	{
	case 0:
		Print(GetNameOfEntity(wife->ID()) += ": Mopping the floor");
		break;
	case 1:
		Print(GetNameOfEntity(wife->ID()) += ": Doing the Dishes");
		break;
	case 2:
		Print(GetNameOfEntity(wife->ID()) += ": making the bed");
		break;

	default:
		break;
	}

}

void DoHouseWork::Exit(MinersWife * wife)
{
}

////////////////////////////////////////////////////// Bathroom state


VisitBathroom * VisitBathroom::Instance()
{
	static VisitBathroom instance;

	return &instance;
}

void VisitBathroom::Enter(MinersWife * wife)
{
	Print(GetNameOfEntity(wife->ID()) += ": Walking to the toilet");
}

void VisitBathroom::Execute(MinersWife * wife)
{
	Print(GetNameOfEntity(wife->ID()) += ": Ahhhhhh Sweet Relief");

	wife->GetFSM()->RevertToPreviousState();

}

void VisitBathroom::Exit(MinersWife * wife)
{
	Print(GetNameOfEntity(wife->ID()) += ": Leaving the shitter!");

}
