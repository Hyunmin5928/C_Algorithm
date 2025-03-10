#include "ArrayStack.h"

// 스택 및 노드 생성/소멸 연산
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
	// 스택 생성 및 초기화

	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	// 노드 생성 및 초기화
	(*Stack)->Nodes = (AS_Node*)malloc(sizeof(AS_Node) *Capacity);

	// Capacity 및 Top 초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

// 사용이 끝난 ArrayStack 메모리 정리
void AS_DestroyStack(ArrayStack* Stack) {
	free(Stack->Nodes);

	free(Stack);
}

// 노드 삽입 연산
void AS_Push(ArrayStack* Stack, ElementType NewData) {
	bool Check = AS_IsFull(Stack);
	if (Check == false) {
		printf("Can't Push data : %d\n", NewData);
	}
	else {
		Stack->Top++;
		Stack->Nodes[Stack->Top].Data = NewData;
	}
}

// 노드 제거 연산 -> Pop은 함수 호출자에게 제거되는 data를 반환해야 함.
ElementType AS_Pop(ArrayStack* Stack) {
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack) {
	return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack* Stack) {
	return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack) {
	return (Stack->Top == -1);
}

bool AS_IsFull(ArrayStack* Stack) {
	if (Stack->Capacity <= (Stack->Top + 1)) {
		return false;
	}
	else {
		return true;
	}
}