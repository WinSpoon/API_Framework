#pragma once
#include "Include.h"

class Bitmap;
class Object
{
protected:
	static map<string, Bitmap*>* ImageList;
public:
	static void SetImageList(map<string, Bitmap*>* _ImageList) { ImageList = _ImageList; }
protected:
	Vector3 position;
	Vector3 scale;
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Destroy()PURE;
public:
	Vector3 GetPosition() const { return position; } 
	void SetPosition(const Vector3& _point) { position = _point; }
public:
	Object();
	virtual ~Object();
};

