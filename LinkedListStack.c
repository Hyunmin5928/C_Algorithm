#include "LinkedListStack.h"

// 스택 생성 연산
void LLS_CreateStack(LLS_Stack** Stack) {
	(*Stack) = (LLS_Stack*)malloc(sizeof(LLS_Stack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

// 스택 소멸 연산
void LLS_DestroyStack(LLS_Stack* Stack) {
	while (!LLS_IsEmpty(Stack)) {
		LLS_Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}
	
	free(Stack);
}

// 스택 내부 노드 생성 연산
LLS_Node* LLS_CreateNode(char* NewData) {
	LLS_Node* NewNode = (LLS_Node*)malloc(sizeof(LLS_Node));
	NewNode->data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->data, NewData);

	NewNode->NextNode = NULL;

	return NewNode;
}


// 노드 소멸 연산
void LLS_DestroyNode(LLS_Node* _Node) {
	free(_Node->data);

	free(_Node);
}

// 노드 삽입 연산
void LLS_Push(LLS_Stack* Stack, LLS_Node* NewNode) {
	if (Stack->List == NULL) {
		Stack->List = NewNode;
	}
	else {
		Stack->Top->NextNode = NewNode;
	}
	Stack->Top = NewNode;
}

// 노드 제거 연산 -> Pop은 상단의 data를 반환하는 함수
LLS_Node* LLS_Pop(LLS_Stack* Stack) {
	LLS_Node* PopNode = Stack->Top;

	if (Stack->List == Stack->Top) {
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else {
		LLS_Node* CurTop = Stack->List;

		while (CurTop != NULL && CurTop->NextNode != Stack->Top) {
			CurTop = CurTop->NextNode;
		}
		Stack->Top = CurTop;
		Stack->Top->NextNode = NULL;
	}
	return PopNode;
}

// 스택의 Top 노드 확인
LLS_Node* LLS_Top(LLS_Stack* Stack) {
	LLS_Node* TopNode = Stack->Top;

	return TopNode;
}

// 스택의 크기 확인
int LLS_GetSIze(LLS_Stack* Stack) {
	int count = 0;
	LLS_Node* CurNode = Stack->List;

	while (CurNode != NULL) {
		CurNode = CurNode->NextNode;
		count++;
	}
	return count;
}

// 스택이 비어있는지 확인
int LLS_IsEmpty(LLS_Stack* Stack) {
	return (Stack->List == NULL);
}
