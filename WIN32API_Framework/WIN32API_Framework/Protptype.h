#pragma once
#include "Include.h"

class GameObject;
class Protptype
{
public:
	Single(Protptype);
private:
	map<string, GameObject*> ProtptypeObject;
public:
	void Start();

	GameObject* GetGameObject(string _key);

private:
	Protptype();
public:
	~Protptype();
};

