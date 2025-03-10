#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

/*CircularQueue 는 FIFO 구조로 먼저 들어온 Data를 Dequeue하는 방식*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
} Node;

typedef struct tagCircularQueue
{
    int Capacity;
    int Front;
    int Rear;

    Node* Nodes;
} CircularQueue;

// 순환 큐 생성/소멸 연산 함수
void CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void CQ_DestroyQueue(CircularQueue* Queue);

// 노드 삽입 연산
void CQ_Enqueue(CircularQueue* Queue, ElementType Data);

// 노드 제거 연산
ElementType CQ_Deque(CircularQueue* Queue);

// 공백 상태 확인
int CQ_IsEmpty(CircularQueue* Queue);

// 포화 상태 확인
int CQ_IsFull(CircularQueue* Queue);

// 큐 사이즈 확인
int CQ_GetSize(CircularQueue* Queue);

#endif