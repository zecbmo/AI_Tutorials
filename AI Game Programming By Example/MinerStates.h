#pragma once
#include "../Common/State.h"





class EnterMineAndDigForNugget :
	public State<Miner>
{
public:
	EnterMineAndDigForNugget();

	//This is a Singleton
	static EnterMineAndDigForNugget* Instance();


	//Trigger when the state is entered
	virtual void Enter(Miner*);

	//Called by the miners update funciton
	virtual void Execute(Miner*);

	//Called when exiting the state
	virtual void Exit(Miner*);

};




class VisitBankAndDepositGold : public State<Miner>
{
public:
	VisitBankAndDepositGold() {};

	//This is a Singleton
	static VisitBankAndDepositGold* Instance();
	
	//Trigger when the state is entered
	virtual void Enter(Miner*);

	//Called by the miners update funciton
	virtual void Execute(Miner*);

	//Called when exiting the state
	virtual void Exit(Miner*);

};


class GoHomeAndSleepTilRested : public State<Miner>
{
public:
	GoHomeAndSleepTilRested() {};

	//This is a Singleton
	static GoHomeAndSleepTilRested* Instance();

	//Trigger when the state is entered
	virtual void Enter(Miner*);

	//Called by the miners update funciton
	virtual void Execute(Miner*);

	//Called when exiting the state
	virtual void Exit(Miner*);

};

class QuenchThirst : public State<Miner>
{
public:
	QuenchThirst() {};

	//This is a Singleton
	static QuenchThirst* Instance();

	//Trigger when the state is entered
	virtual void Enter(Miner*);

	//Called by the miners update funciton
	virtual void Execute(Miner*);

	//Called when exiting the state
	virtual void Exit(Miner*);

};