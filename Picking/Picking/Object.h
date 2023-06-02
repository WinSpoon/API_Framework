#pragma once
#include "Include.h"

class Object
{
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Destroy()PURE;
public:
	Object();
	virtual ~Object();
};

