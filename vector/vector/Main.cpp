#include <iostream>
#include <vector>

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
		//cout << Numbers[i] << endl;
	}



	vector<int> vecList;

	for (int i = 0; i < 5; ++i)
	{
		vecList.push_back(i * 10 + 10);

		cout << vecList[i] << endl;
		cout << vecList.capacity() << endl << endl;
	}


	return 0;
}
