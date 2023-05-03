#pragma once
#include "Include.h"

class GameObject;
class MainUpdate
{
private:
	HDC m_hdc;

	GameObject* m_pPlayer;
	GameObject* m_pEnemy;
public:
	void Start();
	void Update();
	void Render();
	void Destroy();
public:
	MainUpdate();
	~MainUpdate();
};

