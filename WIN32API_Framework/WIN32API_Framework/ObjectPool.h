#pragma once
#include "Include.h"

class GameObject;
class ObjectPool
{
public:
	Single(ObjectPool)
private:
	map<string, list<GameObject*>> PoolList;
public:
	list<GameObject*>* GetList(string _key) 
	{
		map<string, list<GameObject*>>::iterator iter = PoolList.find(_key);

		if (iter == PoolList.end())
			return nullptr;
		
		return &iter->second;
	}

	GameObject* GetGameObject(string _key)
	{
		list<GameObject*>* tempList = GetList(_key);

		if (tempList == nullptr || tempList->empty())
			return nullptr;

		GameObject* Obj = tempList->front();
		tempList->pop_front();

		return Obj;
	}

	void ReturnObject(GameObject* _Object);
private:
	ObjectPool();
public:
	~ObjectPool();
};