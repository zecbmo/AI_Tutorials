#pragma once

#include<string>
#include<iostream>

class Miner;


template <class entity_type>
class State
{
public:
	
	//Trigger when the state is entered
	virtual void Enter(entity_type*) = 0;

	//Called by the miners update funciton
	virtual void Execute(entity_type*) = 0;

	//Called when exiting the state
	virtual void Exit(entity_type*) = 0;

protected:

	void Print(std::string text);

};

template<class entity_type>
inline void State<entity_type>::Print(std::string text)
{
	std::cout << text << std::endl;
}
