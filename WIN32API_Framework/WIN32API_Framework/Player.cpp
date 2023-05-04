#include "Player.h"
#include "Bullet.h"
#include "ObjectManager.h"


Player::Player()
{

}

Player::~Player()
{

}

GameObject* Player::Start()
{
	transform.position = Vector3(WIDTH * 0.5f, HEIGHT * 0.5f, 0.0f);
	transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(100.0f, 100.0f, 0.0f);

	Speed = 5.0f;

	return this;
}

int Player::Update()
{

	if (GetAsyncKeyState(VK_UP))
		transform.position.y -= Speed;

	if (GetAsyncKeyState(VK_DOWN))
		transform.position.y += Speed;

	if (GetAsyncKeyState(VK_LEFT))
		transform.position.x -= Speed;

	if (GetAsyncKeyState(VK_RIGHT))
		transform.position.x += Speed;

	if (GetAsyncKeyState(VK_SPACE))
	{
		ObjectManager::GetInstance()->AddObject( CreateBullet() );
	}

	return 0;
}

void Player::Render(HDC hdc)
{
	Rectangle(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));
}

void Player::Destroy()
{

}

GameObject* Player::CreateBullet()
{
	GameObject* bullet = new Bullet;
	bullet->Start(transform.position);
	
	return bullet;
}