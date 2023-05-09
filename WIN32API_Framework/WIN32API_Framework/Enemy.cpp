#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

GameObject* Enemy::Start()
{
	srand((unsigned int)GetTickCount64());
	transform.position = Vector3(WIDTH + 75.0f, float(rand() % (HEIGHT - 150) + 75), 0.0f);
	transform.direction = Vector3(-1.0f, 0.0f, 0.0f);
	transform.scale = Vector3(150.0f, 150.0f, 0.0f);

	Speed = 0.5f;
	Key = "Enemy";

	return this;
}

int Enemy::Update()
{
	transform.position += transform.direction * Speed;

	if (transform.position.x < 0)
		return 2;

	return 0;

}

void Enemy::Render(HDC hdc)
{
	Ellipse(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));
}

void Enemy::Destroy()
{

}

