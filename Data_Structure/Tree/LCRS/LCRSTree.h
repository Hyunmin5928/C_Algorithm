#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

// 노드 선언
typedef char ElementType;

typedef struct tagLCRSNode {
    struct tagLCRSNode* LeftChild;
    struct tagLCRSNode* RightSibling;

    ElementType Data;
} LCRSNode;

// 노드 생성/소멸 연산
LCRSNode* LCRS_CreateNode(ElementType NewData);
void LCRS_DestroyNode(LCRSNode* _Node);

// 트리 소멸 연산
void LCRS_DestroyTree(LCRSNode* Root);

// 자식 노드 연결
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child);

// 트리 출력
void LCRS_PrintTree(LCRSNode* Node, int Depth);

#endif