#pragma once

#include<string>
#include<iostream>

class Miner;

class State
{
public:
	State() {};
	virtual ~State();

	//Trigger when the state is entered
	virtual void Enter(Miner*) = 0;

	//Called by the miners update funciton
	virtual void Execute(Miner*) = 0;

	//Called when exiting the state
	virtual void Exit(Miner*) = 0;

protected:

	void Print(std::string text);

};

