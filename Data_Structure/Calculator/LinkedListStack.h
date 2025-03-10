#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//typedef char ElementType;

typedef struct s_LLS_Node {
	char* data;
	struct s_LLS_Node* NextNode;
}LLS_Node;

typedef struct s_LLS_Stack {
	LLS_Node* List;
	LLS_Node* Top;
}LLS_Stack;

void LLS_CreateStack(LLS_Stack** Stack);
void LLS_DestroyStack(LLS_Stack* Stack);

LLS_Node* LLS_CreateNode(char* NewData);
void LLS_DestroyNode(LLS_Node* _Node);

void LLS_Push(LLS_Stack* Stack, LLS_Node* NewNode);
LLS_Node* LLS_Pop(LLS_Stack* Stack);

LLS_Node* LLS_Top(LLS_Stack* Stack);
int LLS_GetSIze(LLS_Stack* Stack);
int LLS_IsEmpty(LLS_Stack* Stack);

#endif