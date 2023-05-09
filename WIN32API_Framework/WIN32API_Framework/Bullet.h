#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	virtual GameObject* Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Bullet();
	virtual ~Bullet();
};

