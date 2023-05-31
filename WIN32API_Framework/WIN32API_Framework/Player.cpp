#include "Player.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "Protptype.h"
#include "ObjectPool.h"

#include "NormalBullet.h"
#include "GuideBullet.h"
#include "Bitmap.h"


Player::Player()
{

}

Player::~Player()
{

}

GameObject* Player::Start()
{
	Attack = false;
	isJumping = false;
	jumpHeight = 10.0f;
	oldY = 0.0f;
	curentY = 0.0f;

	frame.CountX = 0;
	frame.CountY = 0;
	frame.EndFrame = 7;
	frame.FrameTime = 150;

	transform.position = Vector3(WIDTH * 0.5f, HEIGHT * 0.5f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(679 / 7, 639 / 9, 0.0f);

	Speed = 5.0f;

	Key = "PlayerR";

	Time = GetTickCount64();
	return this;
}

int Player::Update()
{
	if (Time + frame.FrameTime < GetTickCount64())
	{
		Time = GetTickCount64();
		++frame.CountX;

		if (frame.CountX == frame.EndFrame)
		{
			frame.CountX = 0;

			if (Attack)
			{
				Attack = false;
				SetFrame(0, 0, 7, 150);
			}
		}
	}

	if (isJumping)
	{
		// ** 누르는 힘
		flightTime += 0.1f;
		float result = (flightTime * flightTime * 0.98f);

		// ** 점프
		transform.position.y += -sinf(90 * PI / 180) * jumpHeight + result;


		// ** 점프일 때 올라가는중인지 떨어지는 중인지를 확인.
		if (curentY < transform.position.y)
			SetFrame(frame.CountX, 3, 3, 50);
		else
			SetFrame(frame.CountX, 2, 3, 50);

		curentY = transform.position.y;


		// ** 최초의 점프 위치를 벗어나면 최초위치로 셋팅.
		if (oldY < transform.position.y)
		{
			flightTime = 0.0f;
			transform.position.y = oldY;
			isJumping = false;
		}
	}

	


	DWORD dwKey = GetSingle(InputManager)->GetKey();	

	if (dwKey & KEYID_SPACE)
	{
		SetFrame(frame.CountX, 0, 7, 1500);
		OnAttack();
	}

	if (dwKey & KEYID_CONTROL)
		OnJump();

	if (!Attack)
	{
		if (dwKey & KEYID_UP)
			transform.position.y -= Speed;

		if (dwKey & KEYID_DOWN)
			transform.position.y += Speed;


		if (GetAsyncKeyState('1'))
			Option = 0;

		if (GetAsyncKeyState('2'))
			Option = 1;


		if (dwKey & KEYID_LEFT)
			transform.direction.x = (-1.0f);
		else if (dwKey & KEYID_RIGHT)
			transform.direction.x = 1.0f;
		else
			transform.direction.x = 0.0f;
	}

	if (transform.direction.x)
	{
		SetFrame(frame.CountX, 2, 7, 500);
		OnMove();
	}
	else if(!isJumping)
		SetFrame(frame.CountX, 0, 7, 1500);

	return 0;
}

void Player::Render(HDC hdc)
{
	TransparentBlt(hdc,	  // 복사해 넣을 그림판 ?!
		int(transform.position.x - transform.scale.x * 0.5f),	// 복사할 영역 시작점 X
		int(transform.position.y - transform.scale.y * 0.5f), 	// 복사할 영역 시작점 Y
		(int)transform.scale.x,		// 복사할 영역 끝부분 X
		(int)transform.scale.y, 	// 복사할 영역 끝부분 Y
		(*m_ImageList)[Key]->GetMemDC(),	// 복사할 이미지 (복사대상)
		transform.scale.x * frame.CountX,  // 복사할 시작점 X
		transform.scale.y * frame.CountY,	// 복사할 시작점 Y
		(int)transform.scale.x, 			// 출력할 이미지의 크기 만큼 X
		(int)transform.scale.y,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));		// 해당 색상을 제외
}

void Player::Destroy()
{

}


template <typename T>
GameObject* Player::CreateBullet(string _Key)
{
	GameObject* Obj = GetSingle(ObjectPool)->GetGameObject(_Key);

	if (Obj == nullptr)
	{
		Bridge* pBridge = new T;
		pBridge->Start();
		((BulletBridge*)pBridge)->SetTarget(this);

		GameObject* ProtoObj = GetSingle(Protptype)->GetGameObject(_Key);

		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			Object->Start();
			Object->SetPosition(transform.position);
			Object->SetKey(_Key);

			pBridge->SetObject(Object);
			Object->SetBridge(pBridge);

			return Object;
		}
		else
			return nullptr;
	}

	Obj->Start();
	Obj->SetPosition(transform.position);
	Obj->SetKey(_Key);

	return Obj;
}

void Player::SetFrame(int _frame, int _locomotion, int _endFrame, float _frameTime)
{
	frame.CountX = _frame;
	frame.CountY = _locomotion;
	frame.EndFrame = _endFrame;
	frame.FrameTime = _frameTime / _endFrame;
}

void Player::OnAttack()
{
	if (Attack)
		return;

	Attack = true;
	SetFrame(0, 5, 4, 1500);

	switch (Option)
	{
	case 0:
		ObjectManager::GetInstance()->AddObject(CreateBullet<NormalBullet>("NormalBullet"));
		break;

	case 1:
		ObjectManager::GetInstance()->AddObject(CreateBullet<GuideBullet>("GuideBullet"));
		break;

	}
}

void Player::OnMove()
{
	transform.position += transform.direction * Speed;
	Key = transform.direction.x < 0 ? "PlayerL" : "PlayerR";
}

void Player::OnJump()
{
	if (isJumping)
		return;

	isJumping = true;
	oldY = transform.position.y;
	frame.CountX = 0;
}

