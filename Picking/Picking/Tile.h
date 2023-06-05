#pragma once
#include "Object.h"

class Tile : public Object
{
private:
	int hor;
	int ver;
	
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Destroy()override;
public:
	Tile();
	virtual ~Tile();
};

