#include "Bullet.h"
#include "ObjectPool.h"
#include "NormalBullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{

}


GameObject* Bullet::Start()
{
	transform.position = Vector3(0.0f, 0.0f, 0.0f);
	transform.direction = Vector3(1.0f, 0.0f, 0.0f);
	transform.scale = Vector3(30.0f, 30.0f, 0.0f);

	Key = "Bullet";

	return this;
}

int Bullet::Update()
{
	if (pBridge)
		pBridge->Update(transform);

	if (transform.position.x > WIDTH)
		return 1;

	return 0;
}

void Bullet::Render(HDC hdc)
{
	if (pBridge)
		pBridge->Render(hdc);
}

void Bullet::Destroy()
{
	GetSingle(ObjectPool)->ReturnObject(this);
}
