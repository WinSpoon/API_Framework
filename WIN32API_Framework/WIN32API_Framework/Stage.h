#pragma once
#include "Scene.h"

class Bitmap;
class GameObject;
class Stage : public Scene
{
private:
	map<string, Bitmap*>* m_mapImageList;
	GameObject* m_pPlayer;
	list<GameObject*>* EnemyList;
	list<GameObject*>* BulletList;
	
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	Stage();
	virtual ~Stage();
};

