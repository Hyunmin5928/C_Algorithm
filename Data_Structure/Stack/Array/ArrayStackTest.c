#include "ArrayStack.h"

int main(void) {
	int i = 0;
	ArrayStack* Stack = NULL;
	bool AS_Bool = true;

	AS_CreateStack(&Stack, 10);

	AS_Push(Stack, 1);
	AS_Push(Stack, 2);
	AS_Push(Stack, 3);
	AS_Push(Stack, 4);
	AS_Push(Stack, 5);
	AS_Push(Stack, 6);
	AS_Push(Stack, 7);
	AS_Push(Stack, 8);
	AS_Push(Stack, 9);
	AS_Push(Stack, 10);

	printf("Capacity : %d, Size : %d, Top : %d\n\n",
		Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));


	AS_Push(Stack, 11);

	for (i = 0; i < 5; i++) {
		if (AS_IsEmpty(Stack)) {
			break;
		}

		printf("Popped : %d, ", AS_Pop(Stack));

		if (!AS_IsEmpty(Stack)) {
			printf("Current Top : %d\n", AS_Top(Stack));
		}
		else {
			printf("Stack is Empty\n");
		}
	}

	AS_DestroyStack(Stack);

	return 0;
}