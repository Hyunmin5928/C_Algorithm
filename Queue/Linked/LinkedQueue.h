#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct tagNode{
    char* Data;
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue{
    Node* Front;
    Node* Rear;
    int count;
}LinkedQueue;

// 링크드 큐 생성/소멸 연산
void LQ_CreateQueue(LinkedQueue** Queue);
void LQ_DestroyQueue(LinkedQueue* Queue);

// 노드 생성/소멸 연산
Node* LQ_CreateNode(char* NewData);
void LQ_DestroyNode(Node* _Node);

// 노드 삽입 연산
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);

// 노드 제거 연산
Node* LQ_Dequeue(LinkedQueue* Queue);

int LQ_IsEmpty(LinkedQueue* Queue);

#endif