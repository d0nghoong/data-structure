#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"myPlaylist.h"

ListHead* createLinkedNode() {
	ListHead* L;
	L = (ListHead*)malloc(sizeof(ListHead));
	L->head = NULL;
	return L;
}

ListCircularHead* createCircularNode() {
	ListCircularHead* M;
	M = (ListCircularHead*)malloc(sizeof(ListCircularHead));
	M->head = NULL;
	return M;
}

void addNode(ListHead* L, char name) {
	ListNode* newNode;
	ListNode* p;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->name = name;
	newNode->link = NULL;
	p = L->head;
	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = newNode;
	}
}

void addCircularNode(ListCircularHead* L, char name) {
	ListCircularNode* newNode;
	ListCircularNode* k;
	newNode = (ListCircularNode*)malloc(sizeof(ListCircularNode));
	newNode->name = name;
	k = L->head;

	if (L->head == NULL) {
		L->head = newNode;
		newNode->llink = newNode;
		newNode->rlink = newNode;
	}
	else {
		while (k->rlink != L->head) {
			k = k->rlink;
		}
		k->rlink = newNode;
		newNode->llink = k;
		newNode->rlink = L->head;
		L->head->llink = newNode;
		
	}
}

void selectList(ListHead* L, ListCircularHead* M, char name) {
	ListNode* temp;
	temp = L->head;
	while (temp->name != name) {
		temp = temp->link;
		if (temp->name == NULL) break;
	}
	if (temp->name != NULL) {
		addCircularNode(M, temp->name);
	}
}

void printCircularList(ListCircularHead*M) {
	ListCircularNode* temp;
	temp = M->head;
	do {
		printf("%c ", temp->name);
		temp = temp->rlink;
	} while (temp != M->head);

}

void printList(ListHead* L) {
	ListNode* temp;
	temp = L->head;
	
	while (temp != NULL) {
		printf("%c ", temp->name);
		temp = temp->link;
	}
}


