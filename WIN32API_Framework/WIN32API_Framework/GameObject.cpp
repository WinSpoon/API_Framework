#include "GameObject.h"

map<string, Bitmap*>* GameObject::m_ImageList = nullptr;


GameObject::GameObject() : Speed(0.0f), pBridge(nullptr)
{
	
}

GameObject::~GameObject()
{
	
}