#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "linkedlist.h";

void main() {
	linkList_h* L;
	L = createdLinkedList();

	printf("\n1.공백 리스트 생성하기!\n");
	printList(L);

	printf("\n2.리스트에 [수]노드 입력하기\n");
	insertFirstNode(L, "수");
	printList(L);

	printf("\n3.리스트 마지막에 [금]노드 입력하기\n");
	insertLastNode(L, "금");
	printList(L);

	printf("\n4.리스트 첫번째에 [월]노드 삼입하기\n");
	insertFirstNode(L, "월");
	printList(L);

	printf("\n5.리스트 공간을 해제하여 공백 리스트 만들기\n");
	freeLinkedList_h(L);
	printList(L);

}