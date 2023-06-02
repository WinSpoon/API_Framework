#include "Tile.h"

Tile::Tile() : check(0)
{
}

Tile::~Tile()
{
}


void Tile::Start()
{
	check = 0;

	position = Vector3(100.0f, 100.0f);
	scale = Vector3(100.0f, 100.0f);
}

void Tile::Update()
{
	POINT ptMouse;

	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd, &ptMouse);

	if (check)
	{
		if (position.x - (scale.x * 0.5f) < ptMouse.x &&
			position.y - (scale.y * 0.5f) < ptMouse.y &&
			ptMouse.x < position.x + (scale.x * 0.5f) &&
			ptMouse.y < position.y + (scale.y * 0.5f))
		{
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				check = !check;
			}
		}
	}
	else
	{

	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		check = !check;
		Sleep(80);
	}
}

void Tile::Render(HDC _hdc)
{
	if (check)
		Rectangle(_hdc,
			int(position.x - (scale.x * 0.5f)),
			int(position.y - (scale.y * 0.5f)),
			int(position.x + (scale.x * 0.5f)),
			int(position.y + (scale.y * 0.5f)));
	else 
		Ellipse(_hdc, 
			int(position.x - (scale.x * 0.5f)),
			int(position.y - (scale.y * 0.5f)),
			int(position.x + (scale.x * 0.5f)),
			int(position.y + (scale.y * 0.5f)));
}

void Tile::Destroy()
{
}
