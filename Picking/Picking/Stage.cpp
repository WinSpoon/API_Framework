#include "Stage.h"
#include "Tile.h"

Stage::Stage() : object(nullptr)
{
}

Stage::~Stage()
{
	Destroy();
}


void Stage::Start()
{
	object = new Tile;
	object->Start();
}

void Stage::Update()
{
	object->Update();
}

void Stage::Render(HDC _hdc)
{
	object->Render(_hdc);
}

void Stage::Destroy()
{
	delete object;
	object = nullptr;
}