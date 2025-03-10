#include "LinkedList.h"

// 노드 생성
Node* SLL_CreateNode(ElementType Newdata) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = Newdata;
	NewNode->NextNode = NULL;

	return NewNode;
}

void SLL_DestroyNode(Node* Node) {
	free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode) {
	if ((*Head) == NULL) {
		*Head = NewNode;
	}
	else {
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

void SLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead) {
	if (Head == NULL) {
		(*Head) = NewHead;
	}
	else {
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

void SLL_RemoveNode(Node** Head, Node* RemoveNode) {
	if (*Head == RemoveNode) {
		*Head = RemoveNode->NextNode;
	}
	else {
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != RemoveNode) {
			Current = Current->NextNode;
		}
		if (Current != NULL) {
			Current->NextNode = RemoveNode->NextNode;
		}
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}
	return Current;
}

int SLL_GetNodeCount(Node* Head) {
	int count = 0;
	
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		count++;
	}
	return count;
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead) {
	if (Head == NULL) {
		(*Head) = NewHead;
	}
	else {
		Node* h_Node = (*Head);
		while (h_Node != NULL && h_Node->NextNode != Current) {
			h_Node = h_Node->NextNode;
		}
		h_Node->NextNode = NewHead;
		NewHead->NextNode = Current;
	}
}

void SLL_DestroyAllNodes(Node** List) {
	Node* Head = SLL_GetNodeAt(*List, 0);
	int count = SLL_GetNodeCount(Head);

	for (int i = 0; i < count; i++) {
		Node* Current = SLL_GetNodeAt(*List, 0);
		SLL_RemoveNode(List, Current);
		SLL_DestroyAllNodes(List);
	}
}