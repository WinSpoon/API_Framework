#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Start()
{
	m_pPlayer = new Player();
	m_pPlayer->Start();

	ObjectManager::GetInstance()->AddObject(
		(new Enemy)->Start());
}

int Stage::Update()
{
	if (m_pPlayer)
		m_pPlayer->Update();

	return 0;
}

void Stage::Render(HDC hdc)
{
	list<GameObject*>* EnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<GameObject*>* BulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");

	if (m_pPlayer)
		m_pPlayer->Render(hdc);

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Render(hdc);
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
			(*iter)->Render(hdc);
	}
}

void Stage::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}
}
