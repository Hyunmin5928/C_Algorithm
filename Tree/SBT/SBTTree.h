#ifndef SIMPLE_BINARY_TREE_H
#define SIMPLE_BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagSBTNode{
    struct tagSBTNode* Left;
    struct tagSBTNode* Right;

    ElementType Data;
} SBTNode;

// 노드 선언
SBTNode* SBT_CreateNode(ElementType NewData);
// 노드 소멸
void SBT_DestroyNode(SBTNode* Node); 
// 후위 순회를 이용한 트리 소멸
void SBT_DestroyTree(SBTNode* Node);

// 전위 순회를 이용한 이진 트리 출력
void SBT_PreorderPrintTree(SBTNode* Node);
// 중위 순회를 이용한 이진 트리 출력
void SBT_InorderPrintTree(SBTNode* Node);
// 후위 순회를 이용한 이진 트리 출력
void SBT_PostorderPrintTree(SBTNode* Node);



#endif