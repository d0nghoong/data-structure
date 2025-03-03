#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "CircularLinkedList.h"
void main() {
	linkedList_h* CL;
	listNode* p;

	CL = createdLinkedList_h();
	printf("(1) 원형리스트 생성하기\n");
	printList(CL);

	printf("\n(2) 원형 연결 리스트에 [월] 노드 삽입하기!\n");
	InsertFirstNode(CL, "월");
	printList(CL);

	printf("\n(3) 원형 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기\n");
	p = searchNode(CL, "월");
	InsertMiddleNode(CL, p, "수");
	printList(CL);

	printf("\n(4) 원형 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기\n");
	p = searchNode(CL, "수");
	InsertMiddleNode(CL, p, "금");
	printList(CL);

	printf("\n (5) 원형 연결 리스트에서 [수] 노드 삭제하기");
	p = searchNode(CL, "수");
	deleteNode(CL, p);
	printList(CL);
}
