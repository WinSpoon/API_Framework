#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	virtual void Start()override;
	virtual void Start(Vector3 _position)override
	{

	}
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Enemy();
	virtual ~Enemy();
};

