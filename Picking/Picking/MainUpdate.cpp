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

	stage = new Stage;
	stage->Start();
}

void MainUpdate::Update()
{
	stage->Update();
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, 0, 0, 1500, 1000);
	stage->Render(m_hdc);
}

void MainUpdate::Destroy()
{
	delete stage; 
	stage = nullptr;
}
