#include <iostream>

using namespace std;

typedef struct tagNode
{
	tagNode* next;
	int value;
}NODE;


NODE* List;


void Push(int value);


int main(void)
{
	// ** 첫번째 노드
	// create
	List = new NODE; 

	// initialize
	List->next = nullptr;
	List->value = 0;

	//===========================================
	// ** 두번째 노드
	// create
	List->next = new NODE;

	// initialize
	List->next->next = nullptr;
	List->next->value = 10;
	
	//===========================================
	// ** 세번째 노드
	// create
	List->next->next = new NODE;

	// initialize
	List->next->next->next = nullptr;
	List->next->next->value = 20;

	//===========================================
	// ** 네번째 노드
	// create
	List->next->next->next = new NODE;

	// initialize
	List->next->next->next->next = nullptr;
	List->next->next->next->value = 30;



	// ** 두번째 노드를 nextNode 에 넘겨준다.
	NODE* nextNode = List->next;


	// ** nextNode가 nullptr이 아니라면 반복.
	while (nextNode != nullptr)
	{
		// ** 출력
		cout << nextNode->value << endl;

		// ** 다음노드로 이동
		nextNode = nextNode->next;
	}
	

	return 0;
}

void Push(int value)
{
	NODE* nextNode = List;

	while (nextNode)
		nextNode = nextNode->next;

	nextNode = new NODE;

	nextNode->value = value;
	nextNode->next = nullptr;
}
