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
	virtual GameObject* Clone()override { return new Bullet(*this); }
public:
	Bullet() ;
	Bullet(Transform _transform) : GameObject(_transform) {}
	virtual ~Bullet();
};

