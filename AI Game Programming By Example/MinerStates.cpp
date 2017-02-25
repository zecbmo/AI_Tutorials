#include "MinerStates.h"
#include "Miner.h"
#include "EntityNames.h"

EnterMineAndDigForNugget::EnterMineAndDigForNugget()
{

}

EnterMineAndDigForNugget * EnterMineAndDigForNugget::Instance()
{
	static EnterMineAndDigForNugget instance;

	return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
	//If the miner isn't at gold mine he must change location

	if (pMiner->Location() != goldmine)
	{
		Print(GetNameOfEntity(pMiner->ID()) += ": Walking to the Gold Mine");

		pMiner->ChangeLocation(goldmine);
	}




}

void EnterMineAndDigForNugget::Execute(Miner* pMiner)
{
	//Digs for gold until he is carrying too many nuggets
	//if thirsty will go to the saloon

	pMiner->AddToGoldCarried(1);

	pMiner->IncreaseFatigue();

	Print(GetNameOfEntity(pMiner->ID()) += ": Picking up a Nugget");

	//if enough mined go put it in bank
	if (pMiner->PocketsFull())
	{
		pMiner->ChangeState(VisitBankAndDepositGold::Instance());
	}

	//if thirsty go get a whiskey
	if (pMiner->Thirsty())
	{
		pMiner->ChangeState(QuenchThirst::Instance());
	}


}

void EnterMineAndDigForNugget::Exit(Miner* pMiner)
{

	Print(GetNameOfEntity(pMiner->ID()) += ": Leaving the Mine");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


VisitBankAndDepositGold * VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;

	return &instance;
}

void VisitBankAndDepositGold::Enter(Miner * pMiner)
{
	//on entry the miner makes sure he is located at the bank
	if (pMiner->Location() != bank)
	{
		
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Goin' to the bank. Yes siree";

		pMiner->ChangeLocation(bank);
	}
}

void VisitBankAndDepositGold::Execute(Miner *pMiner)
{
}

void VisitBankAndDepositGold::Exit(Miner *pMiner)
{
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


GoHomeAndSleepTilRested * GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;

	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner *pMiner)
{
}

void GoHomeAndSleepTilRested::Execute(Miner *pMiner)
{
}

void GoHomeAndSleepTilRested::Exit(Miner *pMiner)
{
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


QuenchThirst * QuenchThirst::Instance()
{
	static QuenchThirst instance;

	return &instance;
}

void QuenchThirst::Enter(Miner *pMiner)
{
}

void QuenchThirst::Execute(Miner *pMiner)
{
}

void QuenchThirst::Exit(Miner *pMiner)
{
}
