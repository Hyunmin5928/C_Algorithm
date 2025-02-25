#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct s_CQ_Node {
	ElementType data;
}CQ_Node;

typedef struct s_CircularQueue {
	int Capacity;
	int Front;
	int Rear;

	CQ_Node* Nodes;
}CircularQueue;

#endif