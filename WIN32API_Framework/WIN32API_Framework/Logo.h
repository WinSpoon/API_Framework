#pragma once
#include "Scene.h"

class GameObject;
class Logo : public Scene
{
private:
	GameObject* obj;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Logo();
	virtual ~Logo();
};

