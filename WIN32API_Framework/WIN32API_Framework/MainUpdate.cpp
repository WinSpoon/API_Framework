#include "MainUpdate.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
}


void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	rcPoint.left = 100;
	rcPoint.top = 100;

	rcPoint.right = 200;
	rcPoint.bottom = 200;
}

void MainUpdate::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{

	}

	if (GetAsyncKeyState(VK_DOWN))
	{

	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		rcPoint.left += -1;
		rcPoint.right += -1;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		rcPoint.right += 1;
		rcPoint.left += 1;
	}

}

void MainUpdate::Render()
{
	//Rectangle(m_hdc, 0, 0, 1280, 720);

	Rectangle(m_hdc, 
		rcPoint.left , 
		rcPoint.top, 
		rcPoint.right, 
		rcPoint.bottom);
}

void MainUpdate::Destroy()
{

}
