#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	void Start();
	void Update();
	void Render(HDC hdc);
	void Destroy();
public:
	Player();
	~Player();
};

