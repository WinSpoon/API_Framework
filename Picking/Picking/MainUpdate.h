#pragma once
#include "Include.h"

class Stage;
class MainUpdate
{
private:
	HDC m_hdc;
	Stage* stage;
public:
	void Start();
	void Update();
	void Render();
	void Destroy();
public:
	MainUpdate();
	~MainUpdate();
};