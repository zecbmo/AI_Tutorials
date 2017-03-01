#include "Locations.h"
#include "Miner.h"
#include "ConsoleUtils.h"
#include "EntityNames.h"
#include "MinersWife.h"

int main()
{
	//create a miner
	Miner miner(ent_Miner_Bob);

	MinersWife Elsa(ent_Elsa);

	//simply run the miner through a few Update calls
	for (int i = 0; i<20; ++i)
	{
		miner.Update();
		Elsa.Update();
		Sleep(800);
	}

	//wait for a keypress before exiting
	PressAnyKeyToContinue();

	return 0;
}