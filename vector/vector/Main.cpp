#include <iostream>
#include <vector>

using namespace std;


int* Numbers;
int Size;
int Capacity;


void pop_back()
{
	if (Size != 0)
		--Size;
}

void push_back(int _value)
{
	if (Size == Capacity)
	{
		int Length = int(Capacity * 0.5f);
		Capacity += Length < 1 ? 1 : Length;
	}

	int* temp = new int[Capacity];

	for (int i = 0; i < Size; ++i)
		temp[i] = Numbers[i];

	delete Numbers;
	Numbers = nullptr;

	Numbers = temp;

	Numbers[Size] = _value;

	++Size;
}


int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		push_back(i * 10 + 10);
		cout << "size : " << Size << endl;
		cout << "capacity : " << Capacity << endl << endl;
	}

	for (int i = 0; i < 10; ++i)
		cout << Numbers[i] << endl;
	return 0;


	return 0;
}
