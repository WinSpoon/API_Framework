#include "Player.h"
#include "Bullet.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Start()
{
	transform.position = Vector3(WIDTH * 0.5f, HEIGHT * 0.5f, 0.0f);
	transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(100.0f, 100.0f, 0.0f);

	Speed = 5.0f;

	for (int i = 0; i < BULLETCOUNT; ++i)
		BulletList[i] = nullptr;
}

int Player::Update()
{
	for (int i = 0; i < BULLETCOUNT; ++i)
	{
		if (BulletList[i] != nullptr)
		{
			if (BulletList[i]->Update())
			{
				delete BulletList[i];
				BulletList[i] = nullptr;
			}
		}
	}	

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
		for (int i = 0; i < BULLETCOUNT; ++i)
		{
			if (BulletList[i] == nullptr)
			{
				BulletList[i] = CreateBullet();
				break;
			}
		}
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

	for (int i = 0; i < BULLETCOUNT; ++i)
		if (BulletList[i] != nullptr)
			BulletList[i]->Render(hdc);
}

void Player::Destroy()
{

}


GameObject* Player::CreateBullet()
{
	GameObject* bullet = new Bullet;
	bullet->Start(transform.position);
	//bullet->SetPosition(transform.position);

	return bullet;
}