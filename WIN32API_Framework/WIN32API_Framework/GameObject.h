#pragma once
#include "Include.h"

class GameObject
{
protected:
	Transform transform;
	int Speed;
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Destroy() = 0;
public:
	GameObject();
	~GameObject();
};