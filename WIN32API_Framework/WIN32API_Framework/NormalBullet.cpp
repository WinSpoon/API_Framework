#include "NormalBullet.h"
#include "Bullet.h"

NormalBullet::NormalBullet()
{
}

NormalBullet::~NormalBullet()
{
}


void NormalBullet::Start()
{
	Speed = 15.0f;
}

void NormalBullet::Update(Transform& transform)
{
	transform.position += transform.direction * Speed;
}

void NormalBullet::Render(HDC hdc)
{
	Ellipse(hdc,
		int(Object->GetPosition().x - (Object->GetScale().x * 0.5f)),
		int(Object->GetPosition().y - (Object->GetScale().y * 0.5f)),
		int(Object->GetPosition().x + (Object->GetScale().x * 0.5f)),
		int(Object->GetPosition().y + (Object->GetScale().y * 0.5f)));
}

void NormalBullet::Destroy()
{

}
