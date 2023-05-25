#include "Protptype.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"


Protptype::Protptype()
{
}

Protptype::~Protptype()
{
}


void Protptype::Start()
{
	Transform transform;

	transform.position = Vector3(0.0f, 0.0f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(0.0f, 0.0f, 0.0f);

	string key = "Player";
	ProtptypeObject.insert(make_pair(key, (new Player(transform))->Start()->SetKey(key)));

	key = "Enemy";
	ProtptypeObject.insert(make_pair(key, (new Enemy(transform))->Start()->SetKey(key)));

	key = "NormalBullet";
	ProtptypeObject.insert(make_pair(key, (new Bullet(transform))->Start()->SetKey(key)));

	key = "GuideBullet";
	ProtptypeObject.insert(make_pair(key, (new Bullet(transform))->Start()->SetKey(key)));
}

GameObject* Protptype::GetGameObject(string _key)
{
	map<string, GameObject*>::iterator iter = ProtptypeObject.find(_key);

	if (iter == ProtptypeObject.end())
		return nullptr;
	else
		return iter->second;
}
