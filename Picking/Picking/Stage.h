#pragma once
#include "Include.h"

class Object;
class Stage
{
private:
	Object* object;
public:
	void Start();
	void Update();
	void Render(HDC _hdc);
	void Destroy();
public:
	Stage();
	~Stage();
};

