#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

using namespace std;

// ** 타일 가로, 세로 최대 개수
#define COUNT_X 7
#define COUNT_Y 4

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


typedef struct tagVector3
{
	float x, y;

	tagVector3() : x(0.0f), y(0.0f) {}
	tagVector3(float _x, float _y) : x(_x), y(_y) {}

}Vector3;



void SetCorsorPosition(const float& _x, const float& _y);
void SetColor(int color);
void Text(const float& _x, const float& _y, const string& _str);



int main(void)
{
	// ** 타일 위치
	Vector3 position;
	position.x = 3;
	position.y = 2;


	// ** 타일 크기
	Vector3 scale;
	scale.x = 6;
	scale.y = 3;



	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (time + 50 < GetTickCount64())
		{
			time = GetTickCount64();

			// ** 화면 청소
			system("cls");

			for (int y = 0; y < COUNT_Y; ++y)
			{
				for (int x = 0; x < COUNT_X; ++x)
				{
					SetColor(7);

					// ** 타일 출력
					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y,
						"┌─┐");

					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 1,
						"│　│");

					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 2,
						"└─┘");


					// ** index 확인.
					int index = y * COUNT_X + x;

					char* buffer = new char[4];
					_itoa(index, buffer, 10);

					SetColor(12);

					Text(position.x - 1 + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 1,
						string(buffer));

				}
			}

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

void SetColor(int _color)
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