#include "CircularQueue.h"

// 순환 큐 생성 소멸 연산
void CQ_CreateQueue(CircularQueue** Queue, int Capacity) {
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

	(*Queue)->Nodes = (CQ_Node*)malloc(sizeof(CQ_Node) * (Capacity + 1));

	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_DestroyQueue(CircularQueue* Queue) {
	free(Queue->Nodes);
	free(Queue);
}

// 노드 삽입 연산
void CQ_Enqueue(CircularQueue* Queue, ElementType data) {

}