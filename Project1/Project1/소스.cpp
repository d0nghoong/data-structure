#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createdLinkedList_h();
void printList(linkedList_h* CL);
void InsertFirstNode(linkedList_h* CL, char* x);
void InsertMiddleNode(linkedList_h* CL, listNode* pre, char* x);
void deleteNode(linkedList_h* CL, listNode* old);
listNode* searchNode(linkedList_h* CL, char* x);

linkedList_h* createdLinkedList_h() {
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));
	CL->head = NULL;
	return CL;
}

void printList(linkedList_h* CL) {
	printf("CL=(");
	listNode* p;
	p = CL->head;
	if (p == NULL)
	{
		printf(")\n");
		return;
	}
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(",");
	} while (p != CL->head);
	printf(")");
}

void InsertFirstNode(linkedList_h* CL, char* x) {
	listNode* temp, * newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		temp = CL->head;
		if (temp->link != CL->head)
		{
			temp = temp->link;
		}
		newNode->link = temp->link;
		temp->link = newNode;
		CL->head = newNode;
	}
}

void InsertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}

}

void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* temp;
	if (CL == NULL) return;
	if (old == NULL) return;
	else if (CL->head == CL->head->link) {
		free(CL->head);
		CL->head = NULL;
		return;
	}
	else {
		temp = CL->head;
		while (temp->link != old)
			temp = temp->link;
		temp->link = old->link;
		if (old == CL->head)
			CL->head = old->link;
		free(old);
	}
}

listNode* searchNode(linkedList_h* CL, char* x) {
	listNode* temp;
	temp = CL->head;
	if (temp == NULL) return NULL;
	do {
		if (strcmp(temp->data, x) == 0)return temp;
		temp = temp->link;
	} while (temp != CL->head);
	return NULL;
}

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
