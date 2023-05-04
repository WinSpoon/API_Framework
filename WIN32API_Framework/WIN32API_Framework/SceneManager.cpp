#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::SetScene(SCENEID _State)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_State)
	{
	case LOGO:
		SceneState = new Logo;
		break;

	case MENU:
		SceneState = new Menu;
		break;

	case STAGE:
		SceneState = new Stage;
		break;
	}
	SceneState->Start();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render(HDC hdc)
{
	SceneState->Render(hdc);
}

void SceneManager::Destroy()
{
	delete SceneState;
	SceneState = nullptr;
}