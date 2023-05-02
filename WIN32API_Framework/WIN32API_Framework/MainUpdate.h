#pragma once
#include "Include.h"


class GameObject;
class MainUpdate
{
private:
	HDC m_hdc;

	RECT rcPoint;
	GameObject* m_pPlayer;
public:
	void Start();
	void Update();
	void Render();
	void Destroy();
public:
	MainUpdate();
	~MainUpdate();
};

