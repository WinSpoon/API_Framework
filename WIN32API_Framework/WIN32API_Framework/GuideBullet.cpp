#include "GuideBullet.h"
#include "GameObject.h"

GuideBullet::GuideBullet()
{
}

GuideBullet::~GuideBullet()
{
}


void GuideBullet::Start()
{
	Speed = 2.5f;
}

void GuideBullet::Update(Transform& transform)
{
	float Horizontal = Target->GetPosition().x - transform.position.x;
	float Vertical = Target->GetPosition().y - transform.position.y;

	float Distance = (float)sqrt((Horizontal * Horizontal) + (Vertical * Vertical));

	Vector3 Direction;

	if (Distance != 0)
		Direction = Vector3(
			Horizontal / Distance,
			Vertical / Distance,
			0.0f);
	else
		Direction = Vector3(0.0f, 0.0f, 0.0f);

	transform.position += Direction * Speed;
}

void GuideBullet::Render(HDC hdc)
{
	Ellipse(hdc,
		int(Object->GetPosition().x - (Object->GetScale().x * 0.5f)),
		int(Object->GetPosition().y - (Object->GetScale().y * 0.5f)),
		int(Object->GetPosition().x + (Object->GetScale().x * 0.5f)),
		int(Object->GetPosition().y + (Object->GetScale().y * 0.5f)));
}

void GuideBullet::Destroy()
{

}
