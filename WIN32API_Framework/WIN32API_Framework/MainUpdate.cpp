#include "MainUpdate.h"
#include "Player.h"


MainUpdate::MainUpdate() : m_pPlayer(NULL)
{
}

MainUpdate::~MainUpdate()
{
	Destroy();
}


void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	m_pPlayer = new Player();
	m_pPlayer->Start();
}

void MainUpdate::Update()
{
	m_pPlayer->Update();
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, 0, 0, 1420, 720);

	m_pPlayer->Render(m_hdc);
}

void MainUpdate::Destroy()
{
	delete m_pPlayer;
	m_pPlayer = NULL;
}
