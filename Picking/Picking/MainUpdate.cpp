#include "MainUpdate.h"
#include "Stage.h"

MainUpdate::MainUpdate() : stage(nullptr)
{
}

MainUpdate::~MainUpdate()
{
	Destroy();
}


void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);
	srand(GetTickCount64());

	stage = new Stage;
	stage->Start();
}

void MainUpdate::Update()
{
	stage->Update();
}

void MainUpdate::Render()
{
	stage->Render(m_hdc);
}

void MainUpdate::Destroy()
{
	delete stage; 
	stage = nullptr;
}
