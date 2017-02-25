#pragma once

#include<cassert>

class BaseGameEntity
{


private:

	//identifying number
	int m_ID;

	//Next valid id - updated with every new object
	static int m_iNextValidID;

	//Called in the Constuctor
	void SetID(int val);

public:

	BaseGameEntity(int id)
	{
		SetID(id);
	}

	virtual ~BaseGameEntity() {};

	//All entities must have an update function

	virtual void Update() = 0;

	int ID() const { return m_ID; };


};