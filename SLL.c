//#include <stdio.h>
//#include <stdlib.h>
//
///*Singly Linked List*/
//typedef int ElementType;
//
//typedef struct tagNode {
//	ElementType Data;
//	struct tagNode* NextNode;
//} Node;
//
//// 노드 생성(자동 메모리로 생성하는 노드는 함수가 return을 반환하면서 주소값이 사라지게 됨.)
//Node* SLL_CreateNode(ElementType NewData) {
//	// Node NewNode;				// 자동 메모리에 새로운 노드 생성 -> 적합하지 않은 방식
//	Node* NewNode = (Node*)malloc(sizeof(Node));
//	NewNode->Data = NewData;
//	NewNode->NextNode = NULL;
//
//	return NewNode;			// NewNode가 생성된 메모리의 주소를 반환
//}							// 함수가 종료되면서 NewNode는 자동 메모리에서 제거된다.
//
//// 노드 소멸
//void SLL_DestroyNode(Node* Node) {
//	free(Node);
//}
//
//// 노드 추가 연산
//void SLL_AppendNode(Node** Head, Node* NewNode) {
//	// Head 노드가 NULL이면 NewNode가 Head 노드가 됨.
//	if ((*Head) == NULL) {
//		*Head = NewNode;
//	}
//	else {
//		// Tail을 찾아 NewNode를 연결해주기
//		Node* Tail = (*Head);
//		while(Tail->NextNode != NULL) {
//			Tail = Tail->NextNode;
//		}
//		Tail->NextNode = NewNode;
//	}
//}
//
//// 노드 탐색 연산
//Node* SLL_GetNodeAt(Node* Head, int Location) {
//	Node* Current = Head;
//
//	while (Current != NULL && (--Location) >= 0) {
//		Current = Current->NextNode;
//	}
//	return Current;
//}
//
//// 노드 삭제 연산
//void SLL_RemoveNode(Node** Head, Node* Remove) {
//	if (*Head == Remove) {
//		*Head = Remove->NextNode;
//	}
//	else {
//		Node* Current = *Head;
//		while (Current != NULL && Current->NextNode != Remove) {
//			Current = Current->NextNode;
//		}
//		if (Current != NULL) {
//			Current->NextNode = Remove->NextNode;
//		}
//	}
//}
//
//// 노드 삽입 연산
//void SLL_InsertNode(Node* Current, Node* NewNode) {
//	NewNode->NextNode = Current->NextNode;
//	Current->NextNode = NewNode;
//}
//
//// 노드 개수 세기 연산
//int SLL_GetNodeCount(Node* Head) {
//	int Count = 0;
//	Node* Current = Head;
//	
//	while (Current != NULL) {
//		Current = Current->NextNode;
//		Count++;
//	}
//	return Count;
//}
//
//int main(void) {
//	Node* List = NULL;
//	Node* NewNode = NULL;
//
//	//NewNode = SLL_CreateNode(117);		// 자유 저장소에 노드 생성
//	//SLL_AppendNode(&List, NewNode);		// 생성한 노드를 List에 추가
//	//NewNode = SLL_CreateNode(119);		// 자유 저장소에 노드 생성
//	//SLL_AppendNode(&List, NewNode);		// 생성한 노드를 List에 추가
//
//	SLL_AppendNode(&List, SLL_CreateNode(117));
//	SLL_AppendNode(&List, SLL_CreateNode(119));
//	SLL_AppendNode(&List, SLL_CreateNode(212));
//	SLL_AppendNode(&List, SLL_CreateNode(313));
//
//	Node* bNode0 = SLL_GetNodeAt(List, 0);
//	Node* bNode1 = SLL_GetNodeAt(List, 1);
//	Node* bNode2 = SLL_GetNodeAt(List, 2);
//	Node* bNode3 = SLL_GetNodeAt(List, 3);
//	
//	printf("Node[0]의 Data = %d\n", bNode0->Data);
//	printf("Node[1]의 Data = %d\n", bNode1->Data);
//	printf("Node[2]의 Data = %d\n", bNode2->Data);
//	printf("Node[3]의 Data = %d\n\n", bNode3->Data);
//
//	SLL_RemoveNode(&List, bNode2);
//	SLL_DestroyNode(bNode2);
//
//	Node* aNode0 = SLL_GetNodeAt(List, 0);
//	Node* aNode1 = SLL_GetNodeAt(List, 1);
//
//	SLL_InsertNode(aNode1, SLL_CreateNode(1));
//
//	Node* aNode2 = SLL_GetNodeAt(List, 2);
//	Node* aNode3 = SLL_GetNodeAt(List, 3);
//
//	//printf("Node[0]의 Data = %d\n", List->Data);
//	//printf("Node[1]의 Data = %d\n", NewNode->Data);
//	printf("Node[0]의 Data = %d\n", aNode0->Data);
//	printf("Node[1]의 Data = %d\n", aNode1->Data);
//	printf("Node[2]의 Data = %d\n", aNode2->Data);
//	printf("Node[3]의 Data = %d\n", aNode3->Data);
//
//	int n_cnt = SLL_GetNodeCount(List);
//
//	printf("\n노드의 개수 : %d\n", n_cnt);
//
//	//printf("%d\n", myNode->Data);
//	//printf("%p\n", myNode->NextNode);
//	//printf("%p\n", &myNode);
//
//	return 0;
//}
//
///*tutorial*/
////typedef struct Pointer_s {
////	int x;
////	int y;
////} Pointer;
////
////int main(void) {
////	Pointer Pstr = { 30, 40 };
////	Pointer* Pstr_ = &Pstr;
////
////	Pointer* ptr = (Pointer*)malloc(sizeof(Pointer));
////	ptr->x = 40;
////	ptr->y = 100;
////	printf("x : %d, y : %d\n", Pstr.x, Pstr.y);
////
////	printf("*x : %d, *y : %d\n", Pstr_->x, Pstr_->y);
////
////	printf("m_x : %d, m_y : %d\n", ptr->x, ptr->y);
////	free(ptr);
////
////	return 0;
////}