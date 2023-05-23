#pragma once
#include "GameObject.h"

template <typename T>
class ObjectFactory
{
public:
	static GameObject* CreateObject()
	{
		GameObject* Obj = new T();
		Obj->Start();

		return Obj;
	}

	static GameObject* CreateObject(const float& _x,const float& _y)
	{
		GameObject* Obj = new T();
		Obj->Start();
		Obj->SetPosition(Vector3(_x, _y));

		return Obj;
	}

	static GameObject* CreateObject(const Vector3& _position)
	{
		GameObject* Obj = new T();
		Obj->Start();
		Obj->SetPosition(_position);

		return Obj;
	}
}; 
