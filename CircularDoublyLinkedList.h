#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int CDLL_ElementType;

typedef struct s_CDLL_Node {
	CDLL_ElementType data;
	struct s_CDLL_Node* PrevNode;
	struct s_CDLL_Node* NextNode;
} CDLL_Node;

CDLL_Node* CDLL_CreateNode(CDLL_ElementType Newdata);
void CDLL_DestroyNode(CDLL_Node* Node);
void CDLL_AppendNode(CDLL_Node** Head, CDLL_Node* NewNode);
void CDLL_InsertAfter(CDLL_Node* Cur, CDLL_Node* NewNode);
void CDLL_RemoveNode(CDLL_Node** Head, CDLL_Node* Remove);
CDLL_Node* CDLL_GetNodeAt(CDLL_Node* Head, int location);
unsigned int CDLL_GetNodeCount(CDLL_Node* Head);

#endif