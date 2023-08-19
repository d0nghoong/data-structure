#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "linkedlist.h";


linkList_h* createdLinkedList(void) {
	linkList_h* L;
	L = (linkList_h*)malloc(sizeof(linkList_h));
	L->head = NULL;
	return L;
}
void freeLinkedList_h(linkList_h* L) {
	listNode* p;

	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void printList(linkList_h* L) {
	listNode* p;
	p = L->head;
	printf("L=(");
	while (p != NULL) {
		printf("% s", p->data);
		p = p->link;
		if (p != NULL) printf(",");
	}
	printf(")");
	printf("\n");
}

void insertFirstNode(linkList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddleNode(linkList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);

	if (L->head = NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre = NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}

}

void insertLastNode(linkList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;

	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		temp = L->head;
		if (temp->link != NULL)temp = temp->link;
		temp->link = newNode;
	}



}

