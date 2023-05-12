#include <iostream>

using namespace std;

typedef struct tagNode
{
	tagNode* next;
	int value;
}NODE;


NODE* List;
NODE* End;
int Length;


void push(int value)
{
	//** create
	NODE* node = new NODE;

	//** initialize
	node->next = nullptr;
	node->value = value;
	
	End->next = node;
	End = node;
	++Length;
}


void insert(int count, int value)
{
	// ** 리스트에 담긴 총 원소의 개수보다 count의 값이 크다면
	// ** 값을 추가할 수 없으므로 종료.
	if (Length < count)
		return;

	// ** 리스트를 들고옴.
	NODE* nextNode = List;

	// ** 카운트의 값 만큼 다음 노드로 이동.
	while (0 < count)
	{
		--count;

		// ** 다음노드로 이동
		nextNode = nextNode->next;
	}
	// ** 이동이 끝났다면 새로운 노드를 추가.

	// ** 새로운 노드 생성
	NODE* newNode = new NODE;
	newNode->next = nullptr;
	newNode->value = value;
	
	// ** 다음 노드를 임시의 저장소에 저장.
	NODE* tempNode = nextNode->next;

	// ** 다음노드를 저장하는 저장소에 새로운 노드를 배치.
	nextNode->next = newNode;

	// ** 새로운 노드가 가르키는 다음노드를 임시공간에 있던 노드로 배치
	newNode->next = tempNode;
}

void remove(int count)
{
	// ** 리스트에 담긴 총 원소의 개수보다 count의 값이 크다면
	// ** 값을 추가할 수 없으므로 종료.
	if (Length < count)
		return;

	// ** 리스트를 들고옴.
	NODE* nextNode = List;

	// ** 카운트의 값 만큼 다음 노드로 이동.
	while (0 < count)
	{
		--count;

		// ** 다음노드로 이동
		nextNode = nextNode->next;
	}

	// ** 다 다음 노드를 임시의 저장소에 저장.
	NODE* tempNode = nextNode->next->next;

	// ** 다음 노드를 삭제.
	delete nextNode->next;
	nextNode->next = nullptr;

	// ** 삭제된 공간에 임시저장했던 노드를 셋팅.
	nextNode->next = tempNode;
}



int main(void)
{
	// ** 첫번째 노드
	// create
	List = new NODE; 

	// initialize
	List->next = nullptr;
	List->value = 0;

	End = List;
	//===========================================
	
	push(10);
	push(20);
	push(30);
	push(40);

	insert(2, 25);
	remove(2);


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