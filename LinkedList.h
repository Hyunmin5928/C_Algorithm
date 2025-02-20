#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct s_Node {
	ElementType data;
	struct s_Node* NextNode;
	// Node* NextNode;
} Node;

Node* SLL_CreateNode(ElementType Newdata);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_InsertAfter(Node* Current, Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewNode);
void SLL_RemoveNode(Node** Head, Node* RemoveNode);
Node* SLL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead);
void SLL_DestroyAllNodes(Node** List);

#endif