#include "Stage.h"
#include "Tile.h"
#include "Bitmap.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Destroy();
}


void Stage::Start()
{
	ImageList["Tile"] = (new Bitmap)->LoadBmp(L"../Resource/Tile.bmp");

	for (int y = 0; y < COUNT_Y; ++y)
	{
		for (int x = 0; x < COUNT_X; ++x)
		{
			Object* tile = new Tile;
			tile->Start();

			tile->SetPosition(
				Vector3(
					(x * SCALE_X) + (SCALE_X * 0.5f),
					(y * SCALE_Y) + (SCALE_Y * 0.5f)));

			TileList.push_back(tile);
		}
	}

	Object::SetImageList(&ImageList);
}

void Stage::Update()
{
	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		(*iter)->Update();
	}
}

void Stage::Render(HDC _hdc)
{
	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		(*iter)->Render(_hdc);
	}
}

void Stage::Destroy()
{
	for (vector<Object*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	TileList.clear();
}