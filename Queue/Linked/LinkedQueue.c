#include "LinkedQueue.h"

// 링크드 큐 생성/소멸 연산
void LQ_CreateQueue(LinkedQueue** Queue){
    // 큐를 자유저장소에 생성
    (*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    (*Queue)->count = 0;
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
}

void LQ_DestroyQueue(LinkedQueue* Queue){
    while(!LQ_IsEmpty(Queue)){
        Node* Popped = LQ_Dequeue(Queue);
        LQ_DestroyNode(Popped);
    }

    // 큐를 자유 저장소에서 할당 해제
    free(Queue);
}

Node* LQ_CreateNode(char* NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(sizeof(NewData) + 1);

    strcpy(NewNode->Data, NewData); // 노드에 데이터 저장

    NewNode->NextNode = NULL;   // 다음 노드에 대한 포인터는 NULL로 초기화

    return NewNode;     // NewNode의 주소를 반환
}

void LQ_DestroyNode(Node* _Node){
    free(_Node->Data);
    free(_Node);
}

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode){
    if(Queue->Front == NULL){
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->count++;
    }
    else{
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
        Queue->count++;
    }
}

Node* LQ_Dequeue(LinkedQueue* Queue){
    // LQ_Dequeue() 함수가 반환할 최상위 노드
    Node* Front = Queue->Front;
    
    if(Queue->Front->NextNode == NULL){
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else{
        Queue->Front = Queue->Front->NextNode;
    }

    Queue->count--;

    return Front;
}

int LQ_IsEmpty(LinkedQueue* Queue){
    return (Queue->Front == NULL);
}