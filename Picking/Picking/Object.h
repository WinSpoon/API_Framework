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
	int Option;
	int Index;
	Vector3 position;
	Vector3 scale;
public:
	virtual void Start()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Destroy()PURE;
public:
	Vector3 GetPosition() const { return position; } 
	void SetPosition(const Vector3& _point) { position = _point; }

	int GetOption() const { return Option; }
	void SetOption(const int& _Option) { Option = _Option; }

	int GetIndex() const { return Index; }
	void SetIndex(const int& _Index) { Index = _Index; }
public:
	Object();
	virtual ~Object();
};

