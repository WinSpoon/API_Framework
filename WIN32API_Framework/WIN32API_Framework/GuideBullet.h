#pragma once
#include "BulletBridge.h"

class GuideBullet : public BulletBridge
{
public:
	virtual void Start()override;
	virtual void Update(Transform& transform)override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;

public:
	GuideBullet();
	virtual ~GuideBullet();
};

