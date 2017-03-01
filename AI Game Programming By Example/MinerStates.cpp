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
		pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
	}

	//if thirsty go get a whiskey
	if (pMiner->Thirsty())
	{
		pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
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
		
		Print(GetNameOfEntity(pMiner->ID()) += ": Goin' to the bank. Yes siree");

		pMiner->ChangeLocation(bank);
	}
}

void VisitBankAndDepositGold::Execute(Miner *pMiner)
{

	//deposit the gold
	pMiner->AddToWealth(pMiner->GoldCarried());

	pMiner->SetGoldCarried(0);

	//SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout <<  GetNameOfEntity(pMiner->ID()) << ": "
		<< "Depositing gold. Total savings now: " << pMiner->Wealth() << std::endl;

	//wealthy enough to have a well earned rest?
	if (pMiner->Wealth() >= ComfortLevel)
	{
		
		Print(GetNameOfEntity(pMiner->ID()) += ": WooHoo! Rich enough for now. Back home to mah li'lle lady");

		pMiner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());
	}

	//otherwise get more gold
	else
	{
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}

}

void VisitBankAndDepositGold::Exit(Miner *pMiner)
{
	Print(GetNameOfEntity(pMiner->ID()) += ": Leavin' the bank");
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


GoHomeAndSleepTilRested * GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;

	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner *pMiner)
{
	if (pMiner->Location() != shack)
	{
		//SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		Print(GetNameOfEntity(pMiner->ID()) += ": Walkin' home");

		pMiner->ChangeLocation(shack);
	}
}

void GoHomeAndSleepTilRested::Execute(Miner *pMiner)
{
	//if miner is not fatigued start to dig for nuggets again.
	if (!pMiner->Fatigued())
	{
		//SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		Print(GetNameOfEntity(pMiner->ID()) += ": What a God darn fantastic nap! Time to find more gold");

		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}

	else
	{
		//sleep
		pMiner->DecreaseFatigue();

		//SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		Print(GetNameOfEntity(pMiner->ID()) += ": ZZZZ... ");
	}
}

void GoHomeAndSleepTilRested::Exit(Miner *pMiner)
{
	Print(GetNameOfEntity(pMiner->ID()) += ": Leaving the house!");
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


QuenchThirst * QuenchThirst::Instance()
{
	static QuenchThirst instance;

	return &instance;
}

void QuenchThirst::Enter(Miner *pMiner)
{
	if (pMiner->Location() != saloon)
	{
		pMiner->ChangeLocation(saloon);

		//SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		Print(GetNameOfEntity(pMiner->ID()) += ": Boy, ah sure is thusty! Walking to the saloon");
	}
}

void QuenchThirst::Execute(Miner *pMiner)
{
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkAWhiskey();

		//SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		Print(GetNameOfEntity(pMiner->ID()) += ": That's mighty fine sippin liquer");

		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}

	else
	{
		//SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\nERROR!\nERROR!\nERROR!";
	}
}

void QuenchThirst::Exit(Miner *pMiner)
{
	Print(GetNameOfEntity(pMiner->ID()) += ": Leaving the saloon, feelin' good");
}
