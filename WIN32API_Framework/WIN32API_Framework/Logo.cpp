#include "Logo.h"
#include "SceneManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Start()
{

}

int Logo::Update()
{
	if (GetAsyncKeyState('A'))
		SceneManager::GetInstance()->SetScene(MENU);

	return 0;
}

void Logo::Render(HDC hdc)
{
	Rectangle(hdc, 500, 500, 600, 600);
}

void Logo::Destroy()
{

}
