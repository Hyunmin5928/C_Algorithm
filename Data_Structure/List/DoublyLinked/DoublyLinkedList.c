#include "DoublyLinkedList.h"

// 노드 생성 연산
DLL_Node* DLL_CreateNode(DLL_ElementType n_data) {
	DLL_Node* NewNode = (DLL_Node*)malloc(sizeof(DLL_Node));

	NewNode->data = n_data;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// 노드에 할당 된 메모리 해제
void DLL_DestroyNode(DLL_Node* Node) {
	free(Node);
}

// 노드 추가 연산(맨 뒤)
void DLL_AppendNode(DLL_Node** Head, DLL_Node* NewNode) {
	if ((*Head) == NULL) {
		*Head = NewNode;
	}
	else {
		DLL_Node* Tail = (*Head);
		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

// 노드 탐색 연산
DLL_Node* DLL_GetNodeAt(DLL_Node* Head, int location) {
	DLL_Node* Current = Head;

	while (Current != NULL && (--location) >= 0) {
		Current = Current->NextNode;
	}
	return Current;
}

// 노드 삭제 연산
void DLL_DeleteNode(DLL_Node** Head, DLL_Node* RemoveNode) {
	if ((*Head) == RemoveNode) {
		*Head = RemoveNode->NextNode;
		if ((*Head) != NULL) {
			(*Head)->PrevNode = NULL;
		}
		RemoveNode->PrevNode = NULL;
		RemoveNode->NextNode = NULL;
	}
	else {
		DLL_Node* Temp = RemoveNode;
		
		if (RemoveNode->PrevNode != NULL) {
			RemoveNode->PrevNode->NextNode = Temp->NextNode;
		}
		if (RemoveNode->NextNode != NULL) {
			RemoveNode->NextNode->PrevNode = Temp->PrevNode;
		}
		RemoveNode->PrevNode = NULL;
		RemoveNode->NextNode = NULL;
	}
}

// 노드 삽입 연산
void DLL_InsertAfter(DLL_Node* Current, DLL_Node* NewNode) {
	NewNode->PrevNode = Current;
	NewNode->NextNode = Current->NextNode;
	
	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}

// 노드 개수 세기 연산
int DLL_GetNodeCount(DLL_Node* Head) {
	unsigned int count = 0;
	DLL_Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		count++;
	}
	return count;
}

void PrintNode(DLL_Node* _Node) {
	if (_Node->PrevNode = NULL) {
		printf("Prev : NULL");
	}
	else {
		printf("Prev: %d", _Node->PrevNode->data);
		printf("Current: %d", _Node->data);
	}
	if (_Node->NextNode == NULL) {
		printf("Next: NULL\n");
	}
	else {
		printf("Next: %d", _Node->NextNode->data);
	}
}
void PrintProceed(DLL_Node* Head) {
	int idx = 0;
	if (Head == NULL) {
		printf("NULL List\n");
	}
	else {
		while (Head != NULL) {
			printf("DLL_Node[%d] -> ", idx);
			if (Head->PrevNode == NULL) {
				printf("Prev data : NULL\t");
				printf("Cur data : %d\t", Head->data);
			}
			else {
				printf("Prev data : %d\t", Head->PrevNode->data);
				printf("Cur data : %d\t", Head->data);
			}
			if (Head->NextNode == NULL) {
				printf("Next data : NULL\n");
			}
			else {
				printf("Next data : %d\n", Head->NextNode->data);
			}
			Head = Head->NextNode;
			idx++;
		}
	}
}

void PrintReverse(DLL_Node* Head) {
	int idx = 0;
	if (Head == NULL) {
		printf("NULL List\n");
	}
	else {
		while (Head->NextNode != NULL) {
			Head = Head->NextNode;
			idx++;
		}
		//printf("%d %d", Head->data, idx);
		while (Head != NULL) {
			printf("DLL_Node[%d] -> ", idx);
			if (Head->PrevNode == NULL) {
				printf("Prev data : NULL\t");
				printf("Cur data : %d\t", Head->data);
			}
			else {
				printf("Prev data : %d\t", Head->PrevNode->data);
				printf("Cur data : %d\t", Head->data);
			}
			if (Head->NextNode == NULL) {
				printf("Next data : NULL\n");
			}
			else {
				printf("Next data : %d\n", Head->NextNode->data);
			}
			Head = Head->PrevNode;
			idx--;
		}
	}
}