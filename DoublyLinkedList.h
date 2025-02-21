#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int DLL_ElementType;

typedef struct s_DLL_Node {
	DLL_ElementType data;
	struct s_DLL_Node* PrevNode;
	struct s_DLL_Node* NextNode;
} DLL_Node;

DLL_Node* DLL_CreateNode(DLL_ElementType n_data);
void DLL_DestroyNode(DLL_Node* Node);
void DLL_AppendNode(DLL_Node** Head, DLL_Node* NewNode);
DLL_Node* DLL_GetNodeAt(DLL_Node* Head, int location);
void DLL_DeleteNode(DLL_Node** Head, DLL_Node* RemoveNode);
void DLL_InsertAfter(DLL_Node* Current, DLL_Node* NewNode);
int DLL_GetNodeCount(DLL_Node* Head);
void PrintNode(DLL_Node* _Node);
void PrintProceed(DLL_Node* Head);
void PrintReverse(DLL_Node* Head);

#endif 