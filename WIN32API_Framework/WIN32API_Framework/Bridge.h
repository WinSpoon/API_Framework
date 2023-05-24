#pragma once
#include "Include.h"


class GameObject;
class Bridge
{
protected:
	GameObject* Object;
public:
	virtual void Start()PURE;
	virtual void Update(Transform& transform)PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	void SetObject(GameObject* _Object) { Object = _Object; }
public:
	Bridge() : Object(nullptr) {}
	virtual ~Bridge() {}
};