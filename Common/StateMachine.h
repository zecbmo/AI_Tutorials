#pragma once
#include "State.h"
#include <cassert>

template <class entity_type>
class StateMachine
{
private:

	//pointer to agent that owns this instance
	entity_type* m_pOwner;

	State<entity_type>* m_pCurrentState;

	//record of the last state the owner was in
	State<entity_type>* m_pPreviousState;

	//state logic called everytime the FSM is updated
	State<entity_type>* m_pGlobalState;

public:

	StateMachine(entity_type* owner)
		:m_pOwner(owner),
		m_pPreviousState(NULL),
		m_pCurrentState(NULL),
		m_pGlobalState(NULL) 
	{}

	//FSM initializers
	void SetCurrentState(State<entity_type>* state) { m_pCurrentState = state; }
	void SetPreviousState(State<entity_type>* state) { m_pPreviousState = state; }
	void SetGlobalState(State<entity_type>* state) { m_pGlobalState = state; }


	void Update() const
	{
		//if a global state exists execute it
		if (m_pGlobalState)
		{
			m_pGlobalState->Execute(m_pOwner);
		}

		if (m_pCurrentState)
		{
			m_pCurrentState->Execute(m_pOwner);
		}

	}

	//change to new state
	void ChangeState(State<entity_type>* pNewState)
	{
		assert(pNewState && "<StateMachine::ChangeState>: trying to change to a null state");

		m_pPreviousState = m_pCurrentState;

		m_pCurrentState->Exit(m_pOwner);

		m_pCurrentState = pNewState;

		m_pCurrentState->Enter(m_pOwner);
		
	}


	//returns to previous state
	void RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}

	//Accessors
	State<entity_type>* CurrentState() const { return m_pCurrentState; }
	State<entity_type>* GlobalState() const { return m_pGlobalState; }
	State<entity_type>* PreviousState() const { return m_pPreviousState; }
	//returns true if the current state’s type is equal to the type of the
	//class passed as a parameter.

	bool isInState(const State<entity_type>& st)const
	{
		if (typeid(*m_pCurrentState) == typeid(st))
		{
			return true;
		}

		return false;
	}
};