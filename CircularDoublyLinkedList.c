#include "CircularDoublyLinkedList.h"

// 노드 생성 연산
CDLL_Node* CDLL_CreateNode(CDLL_ElementType Newdata) {
	CDLL_Node* NewNode = (CDLL_Node*)malloc(sizeof(CDLL_Node));

	NewNode->data = Newdata;
	NewNode->PrevNode = NewNode;
	NewNode->NextNode = NewNode;

	return NewNode;
}

// 노드 메모리 해제
void CDLL_DestroyNode(CDLL_Node* Node) {
	free(Node);
}

// 노드 삽입 연산(tail 다음)
void CDLL_AppendNode(CDLL_Node** Head, CDLL_Node* NewNode) {
	if ((*Head) == NULL) {
		*Head = NewNode;
		(*Head)->PrevNode = NewNode;
		(*Head)->NextNode = NewNode;
	}
	else {
		CDLL_Node* Tail = (*Head)->PrevNode;

		(*Head)->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail;
	}
}

// 노드 삽입 연산(해당 노드 뒤에)
void CDLL_InsertAfter(CDLL_Node* Cur, CDLL_Node* NewNode) {
	NewNode->PrevNode = Cur;		
	NewNode->NextNode = Cur->NextNode;

	if (Cur->NextNode != NULL) {
		Cur->NextNode->PrevNode = NewNode;
		Cur->NextNode = NewNode;
	}
}

//노드 삭제 연산
void CDLL_RemoveNode(CDLL_Node** Head, CDLL_Node* Remove) {
	if (*Head == Remove) {
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;

		(*Head) = Remove->NextNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else {
		Remove->PrevNode->NextNode = Remove->NextNode;
		Remove->NextNode->PrevNode = Remove->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

CDLL_Node* CDLL_GetNodeAt(CDLL_Node* Head, int location){
	CDLL_Node* Cur = Head;

	while(Cur != NULL && (--location) >= 0) {
		Cur = Cur->NextNode;
	}

	return Cur;
}

unsigned int CDLL_GetNodeCount(CDLL_Node* Head) {
	unsigned int count = 0;

	CDLL_Node* Cur = Head;

	while (Cur != NULL) {
		Cur = Cur->NextNode;
		count++;

		if (Cur == Head) {
			break;
		}
	}
	return count;
}