#include "Tile.h"
#include "Bitmap.h"

Tile::Tile() : hor(0), ver(0)
{
	
}

Tile::~Tile()
{
}


void Tile::Start()
{
	position = Vector3(0.0f, 0.0f);
	scale = Vector3(SCALE_X, SCALE_Y);

	hor = 0;
	ver = 0;
}

void Tile::Update()
{
	POINT ptMouse;

	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd, &ptMouse);

	if (position.x - (scale.x * 0.5f) < ptMouse.x &&
		position.y - (scale.y * 0.5f) < ptMouse.y &&
		ptMouse.x < position.x + (scale.x * 0.5f) &&
		ptMouse.y < position.y + (scale.y * 0.5f))
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			++hor;

			if (hor >= 4)
			{
				hor = 0;
				ver = !ver;
			}

			Sleep(80);
		}
	}

}

void Tile::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(position.x - (scale.x * 0.5f)),
		int(position.y - (scale.y * 0.5f)),		
		(int)scale.x, (int)scale.y,
		(*ImageList)["Tile"]->GetMemDC(),
		int(scale.x * hor),
		int(scale.x * ver),
		(int)scale.x, (int)scale.y,
		RGB(255, 0, 255));
}

void Tile::Destroy()
{

}
