#pragma once
#include "Include.h"

class Bitmap;
class Bridge;
class GameObject
{
protected:
	Frame frame;
	ULONGLONG Time;

	Transform transform;
	float Speed;
	string Key;

	Bridge* pBridge;
	static map<string, Bitmap*>* m_ImageList;
public:
	static void SetImageList(map<string, Bitmap*>* _ImageList) { m_ImageList = _ImageList; }
public:
	virtual GameObject* Start()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	virtual GameObject* Clone()PURE;
public:
	string GetKey()const { return Key; }
	GameObject* SetKey(const string& _key) {  Key = _key; return this; }

	Transform GetTransform()const { return transform; }

	Vector3 GetPosition()const { return transform.position; }
	void SetPosition(const Vector3& _position) { transform.position = _position; }

	Vector3 GetScale()const { return transform.scale; }
	void SetScale(const Vector3& _scale) { transform.scale = _scale; }

	void SetBridge(Bridge* _bridge) { pBridge = _bridge; }
public:
	GameObject();
	GameObject(Transform _transform) : transform(_transform), Speed(0.0f), pBridge(nullptr){}
	virtual ~GameObject();
};