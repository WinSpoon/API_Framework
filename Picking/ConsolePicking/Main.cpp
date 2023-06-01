#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

// ** 타일 가로, 세로 최대 개수
#define COUNT_X 5
#define COUNT_Y 5

#define BLACK		0
#define DARKBLUE	1
#define DARKGREEN	2
#define DARKSKYBLUE 3
#define DARKRED		4
#define DARKPURPLE	5
#define DARKYELLOW	6
#define GRAY		7
#define DARKGRAY	8
#define BLUE		9
#define GREEN		10
#define SKYBLUE		11
#define RED			12
#define PURPLE		13
#define YELLOW		14
#define WHITE		15


void SetCorsorPosition(const float& _x, const float& _y);
void SetColor(const int& _color);
void Text(const float& _x, const float& _y, const string& _str);



typedef struct tagVector3
{
	float x, y;

	tagVector3() : x(0.0f), y(0.0f) {}
	tagVector3(float _x, float _y) : x(_x), y(_y) {}

}Vector3;



typedef struct tagTile
{
	Vector3 position[3];
	string tile[3];
	int option;

	void Render()
	{
		for (int i = 0; i < 3; ++i)
			Text(position[i].x, position[i].y, tile[i]);
	}

	tagTile() : option(0) {}

}Tile;


typedef struct tagInfo
{
	Vector3 position;
	string tile;
	int option;

	tagInfo() : option(0) {}

}Info;


// ** 타일 크기
const Vector3 scale(6, 3);


int main(void)
{
	// ** 타일 위치
	vector<Tile*> TileList;

	int x = 0;
	int y = 0;

	for (int i = 0; i < COUNT_Y * COUNT_X; ++i)
	{
		Tile* tile = new Tile;

		tile->tile[0] = "┌─┐";
		tile->position[0] = Vector3(x * scale.x, y * scale.y);

		tile->tile[1] = "│　│";
		tile->position[1] = Vector3(x * scale.x, y * scale.y + 1);

		tile->tile[2] = "└─┘";
		tile->position[2] = Vector3(x * scale.x, y * scale.y + 2);

		x++;

		if (x == 5)
		{
			x = 0;
			y++;
		}

		TileList.push_back(tile);
	}

	// ** Target
	Info Cursur;
		   
	Cursur.position = Vector3(15.0f, 8.0f);
	Cursur.option = 0;


	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (time + 50 < GetTickCount64())
		{
			time = GetTickCount64();

			// ** 화면 청소
			system("cls");


			int X = Cursur.position.x / scale.x;
			int Y = Cursur.position.y / scale.y;

			int index = Y * COUNT_Y + X;


			for (vector<Tile*>::iterator iter = TileList.begin(); iter != TileList.end(); ++iter)
				(*iter)->Render();


			// ** CPU가 연산을 하지 않는 상태.
			Sleep(50);
		}
	}
	
	SetColor(7);

	return 0;
}


void SetCorsorPosition(const float& _x, const float& _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(const int& _color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(
		handle, _color);
}

void Text(const float& _x, const float& _y, const string& _str) 
{
	SetCorsorPosition(_x, _y);
	cout << _str << endl;
}