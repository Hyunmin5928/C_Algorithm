#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

// 스택의 각 층을 구성하는 노드 구조체
typedef struct s_AR_Node {
	ElementType Data;
} AS_Node;

// 스택 구조체
typedef struct s_ArrayStack {
	int Capacity;
	int Top;
	AS_Node* Nodes;
} ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, ElementType NewData);
ElementType AS_Pop(ArrayStack* Stack);
ElementType AS_Top(ArrayStack* Stack);
int AS_GetSize(ArrayStack* Stack);
int AS_IsEmpty(ArrayStack* Stack);
bool AS_IsFull(ArrayStack* Stack);

#endif