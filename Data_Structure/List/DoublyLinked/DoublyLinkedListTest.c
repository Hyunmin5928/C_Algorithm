#include "DoublyLinkedList.h"

int main(void){
	unsigned int count = 0;
	DLL_Node* D_List = NULL;
	DLL_Node* D_Current = NULL;
	DLL_Node* D_NewNode = NULL;

	// 노드 5개 추가
	for (int i = 0; i < 5; i++) {
		D_NewNode = DLL_CreateNode((i + 1) * i);
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
	for (int i = 0; i < (int)count; i++) {
		D_Current = DLL_GetNodeAt(D_List, 0);
		if (D_Current != NULL) {
			DLL_DeleteNode(&D_List, D_Current);
			DLL_DestroyNode(D_Current);
		}
	}
    
    return 0;
}