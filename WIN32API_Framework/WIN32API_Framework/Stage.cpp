#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"
#include "ObjectPool.h"
#include "Protptype.h"

#include <tchar.h>

Stage::Stage() : m_pPlayer(nullptr), EnemyList(nullptr), BulletList(nullptr)
{

}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	GetSingle(Protptype)->Start();

	{
		GameObject* ProtoObj = GetSingle(Protptype)->GetGameObject("Player");

		if (ProtoObj != nullptr)
		{
			m_pPlayer = ProtoObj->Clone();
			m_pPlayer->Start();
		}
	}


	{
		GameObject* ProtoObj = GetSingle(Protptype)->GetGameObject("Enemy");

		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			ObjectManager::GetInstance()->AddObject(
				Object->Start());
		}
	}

	EnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
}

int Stage::Update()
{
	if (m_pPlayer)
		m_pPlayer->Update();

	ObjectManager::GetInstance()->Update();

	return 0;
}

void Stage::Render(HDC hdc)
{
	if (m_pPlayer)
		m_pPlayer->Render(hdc);

	ObjectManager::GetInstance()->Render(hdc);

#ifdef DEBUG
	list<GameObject*>* enemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<GameObject*>* normalList = ObjectManager::GetInstance()->GetObjectList("NormalBullet");
	list<GameObject*>* guideList = ObjectManager::GetInstance()->GetObjectList("GuideBullet");

	if (enemyList != nullptr && !enemyList->empty())
	{
		// ** Buffer 생성
		// ** 배열의 길이는 중요하지 않음. (충분하면 됨.)
		char* enemyBuffer = new char[128];

		// ** 정수를 문자열로 변환. 10진수로 변환됨.
		_itoa((int)enemyList->size(), enemyBuffer, 10);

		// ** 문자열 포인터를 string 으로 변환.
		string str(enemyBuffer);

		// ** 문자열 포인터 배열 삭제.
		delete[] enemyBuffer;
		enemyBuffer = nullptr;

		// ** 유니코드형태로 생성.
		wchar_t* t = new wchar_t[(int)str.size()];

		// ** 문자열 복사.
		mbstowcs(t, str.c_str(), (int)str.size());

		// ** 출력
		TextOut(hdc, 50, 50, (LPCWSTR)t, (int)str.size());
	}

	if (normalList != nullptr && !normalList->empty())
	{
		char* NormalBuffer = new char[128];
		_itoa((int)normalList->size(), NormalBuffer, 10);

		string str(NormalBuffer);

		delete[] NormalBuffer;
		NormalBuffer = nullptr;

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());

		TextOut(hdc, 50, 70, (LPCWSTR)t, (int)str.size());
	}

	if (guideList != nullptr && !guideList->empty())
	{
		char* GuideBuffer = new char[128];
		_itoa((int)guideList->size(), GuideBuffer, 10);

		string str(GuideBuffer);

		delete[] GuideBuffer;
		GuideBuffer = nullptr;

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());

		TextOut(hdc, 50, 90, (LPCWSTR)t, (int)str.size());
	}

	list<GameObject*>* NormalBulletList = GetSingle(ObjectPool)->GetList("NormalBullet");
	list<GameObject*>* GuideBulletList = GetSingle(ObjectPool)->GetList("GuideBullet");

	if (NormalBulletList != nullptr && !NormalBulletList->empty())
	{
		char* normalBuffer = new char[128];
		_itoa((int)NormalBulletList->size(), normalBuffer, 10);

		string str(normalBuffer);

		delete[] normalBuffer;
		normalBuffer = nullptr;

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());

		TextOut(hdc, 120, 50, (LPCWSTR)t, (int)str.size());
	}

	if (GuideBulletList != nullptr && !GuideBulletList->empty())
	{
		char* GuideBuffer = new char[128];
		_itoa((int)GuideBulletList->size(), GuideBuffer, 10);

		string str(GuideBuffer);

		delete[] GuideBuffer;
		GuideBuffer = nullptr;

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());

		TextOut(hdc, 120, 70, (LPCWSTR)t, (int)str.size());
	}
#endif // DEBUG
}

void Stage::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		EnemyList->clear();
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		BulletList->clear();
	}
}
