﻿#include "LinkedListStack.h"

int main(void) {
	int i = 0;
	int count = 0;
	LLS_Node* Popped;
	LLS_Stack* Stack;

	LLS_CreateStack(&Stack);

	LLS_Push(Stack, LLS_CreateNode("abc"));
	LLS_Push(Stack, LLS_CreateNode("def"));
	LLS_Push(Stack, LLS_CreateNode("efg"));
	LLS_Push(Stack, LLS_CreateNode("hij"));
	LLS_Push(Stack, LLS_CreateNode("kln"));
	LLS_Push(Stack, LLS_CreateNode("mop"));

	count = LLS_GetSIze(Stack);

	printf(" Size : %d, Top : %s\n\n", count, LLS_Top(Stack)->data);

	for (i = 0; i < count; i++) {
		if (LLS_IsEmpty(Stack)) {
			break;
		}

		Popped = LLS_Pop(Stack);
		printf("Popped : %s, ", Popped->data);

		LLS_DestroyNode(Popped);

		if (!LLS_IsEmpty(Stack)) {
			printf("Current Top : %s\n", LLS_Top(Stack)->data);
		}
		else {
			printf("Stack is Empty.\n");
		}
	}

	LLS_DestroyStack(Stack);
	return 0;
}