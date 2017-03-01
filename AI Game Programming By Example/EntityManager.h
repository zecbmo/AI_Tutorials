#pragma once

#include<map>
#include<cassert>
#include <string>


class BaseGameEntity;

#define EntityMgr EntityManager::Instance()

class EntityManager
{
private:
	typedef std::map<int, BaseGameEntity*> EnityMap;

	EnityMap m_EntityMap;

public:
	EntityManager();
	~EntityManager();

	static EntityManager* Instance();

	void RegisterEntity(BaseGameEntity* NewEntity);

	BaseGameEntity* GetEntityFromID(int id) const;

	void RemoveEntity(BaseGameEntity* pEntity);

};

