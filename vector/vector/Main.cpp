#include <iostream>

using namespace std;

int* Numbers = nullptr;
int Length = 0;

void push(int n)
{
	if (Numbers == nullptr)
	{
		Numbers = new int;
		*Numbers = n;
		++Length;
		return;
	}

	int* Temp = new int[Length + 1];

	for (int i = 0; i < Length; ++i)
		Temp[i] = Numbers[i];
	
	Temp[Length] = n;
	Numbers = Temp;
	++Length;
}


int main(void)
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	for (int i = 0; i < Length; ++i)
	{
		cout << Numbers[i] << endl;
	}

	return 0;
}
