#include "ObjectPool.h"



ObjectPool::ObjectPool()
{
}


ObjectPool::~ObjectPool()
{
}


void ObjectPool::ReturnObject(GameObject* _Object)
{
	PoolList.push_back(_Object);
}