#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 스택의 각 층을 구성하는 노드 구조체
typedef struct s_AR_Node {
	ElementType data;
} AR_Node;

// 스택 구조체
typedef struct s_ArrayStack {
	int Capacity;
	int top;
	AR_Node* Nodes;
} ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity) {

}

#endif