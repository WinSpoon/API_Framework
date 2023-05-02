#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Start()
{
	transform.position = new Vector3(700.0f, 350.0f, 0.0f);
	transform.rotation = new Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = new Vector3(100.0f, 100.0f, 0.0f);
}

void Player::Update()
{
	if (GetAsyncKeyState(VK_UP))
		transform.position->y -= 5.0f;

	if (GetAsyncKeyState(VK_DOWN))
		transform.position->y += 5.0f;

	if (GetAsyncKeyState(VK_LEFT))
		transform.position->x -= 5.0f;

	if (GetAsyncKeyState(VK_RIGHT))
		transform.position->x += 5.0f;
}

void Player::Render(HDC hdc)
{
	Rectangle(hdc,
		int(transform.position->x - (transform.scale->x * 0.5f)),
		int(transform.position->y - (transform.scale->y * 0.5f)),
		int(transform.position->x + (transform.scale->x * 0.5f)),
		int(transform.position->y + (transform.scale->y * 0.5f)));
}

void Player::Destroy()
{

}
