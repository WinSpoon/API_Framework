#include "Menu.h"
#include "SceneManager.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Start()
{

}

int Menu::Update()
{

	if (GetAsyncKeyState('S'))
		SceneManager::GetInstance()->SetScene(STAGE);

	return 0;
}

void Menu::Render(HDC hdc)
{
	Ellipse(hdc, 500, 500, 600, 600);
}

void Menu::Destroy()
{

}
