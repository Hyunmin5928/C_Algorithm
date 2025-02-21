#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularDoublyLinkedList.h"

void singly_Node_test(void) {
	int count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	for (int i = 0; i < 5; i++) {
		NewNode = SLL_CreateNode(i * 4);
		SLL_AppendNode(&List, NewNode);
	}
	NewNode = SLL_CreateNode(-1);
	SLL_AppendNode(&List, NewNode);

	NewNode = SLL_CreateNode(-2);
	SLL_AppendNode(&List, NewNode);

	// List 출력
	count = SLL_GetNodeCount(List);
	for (int i = 0; i < count; i++) {
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] = %d\n", i, Current->data);
	}

	printf("\nInserting 3000 After index [2]...\n\n");

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(2000);
	SLL_InsertAfter(Current, NewNode);

	Current = SLL_GetNodeAt(List, 1);
	NewNode = SLL_CreateNode(4000);
	SLL_InsertBefore(&List, Current, NewNode);

	// List 출력
	count = SLL_GetNodeCount(List);
	for (int i = 0; i < count; i++) {
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] = %d\n", i, Current->data);
	}

	printf("\nDestroying List\n");
	//for (int i = 0; i < count; i++) {
	//	Current = SLL_GetNodeAt(List, 0);
	//	if (Current != NULL) {
	//		printf("Destroy Data of List = %d\n", Current->data);
	//		SLL_RemoveNode(&List, Current);
	//		SLL_DestroyNode(Current);
	//	}
	//}

	SLL_DestroyAllNodes(&List);
	count = SLL_GetNodeCount(List);
	for (int i = 0; i < count; i++) {
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] = %d\n", i, Current->data);
	}

	return 0;
}

void doubly_Linked_Node_test(void) {
	unsigned int count = 0;
	DLL_Node* D_List = NULL;
	DLL_Node* D_Current = NULL;
	DLL_Node* D_NewNode = NULL;

	// 노드 5개 추가
	for (int i = 0; i < 5; i++) {
		D_NewNode = DLL_CreateNode((i + 1)*i);
		DLL_AppendNode(&D_List, D_NewNode);
	}
	
	// 리스트 출력
	count = DLL_GetNodeCount(D_List);
	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		D_Current = DLL_GetNodeAt(D_List, i);
		printf("Double Linked list[%d] = %d\n", i, D_Current->data);
	}

	printf("PrintProcees func start.\n");
	PrintProceed(D_List);

	printf("PrintReverse func start.\n");
	PrintReverse(D_List);

	printf("\nRemove all DLL_Nodes\n");
	for (int i = 0; i < count; i++) {
		D_Current = DLL_GetNodeAt(D_List, 0);
		if (D_Current != NULL) {
			DLL_DeleteNode(&D_List, D_Current);
			DLL_DestroyNode(D_Current);
		}
	}
}

void Circular_Doubly_Linked_Node_Test(void) {
	unsigned int count = 0;
	CDLL_Node* C_List = NULL;
	CDLL_Node* C_Current = NULL;
	CDLL_Node* C_NewNode = NULL;

	
}

int main(void) {
	//singly_Node_test();
	//doubly_Linked_Node_test();
	//Circular_Doubly_Linked_Node_Test();
}