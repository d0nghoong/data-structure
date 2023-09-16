#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"LinkedPoly.h"

ListHead* createLinkedList() {
	ListHead* L;
	L = (ListHead*)malloc(sizeof(ListHead));
	L->head = NULL;
	return L;
}

void appendTerm(ListHead* L, float coef, int expo) {
	ListNode* newNode;
	ListNode* p;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;
	if (L->head == NULL) {
		L->head = newNode;
	}
	else {
		p = L->head;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = newNode;
	}
}

void addPoly(ListHead* A, ListHead* B, ListHead* C) {
	ListNode* PA;
	ListNode* PB;
	PA = A->head;
	PB = B->head;
	float sum;

	while (PA && PB) {
		if (PA->expo == PB->expo) {
			sum = PA->coef + PB->coef;
			appendTerm(C, sum, PA->expo);
			PA = PA->link;
			PB = PB->link;
		}
		else if (PA->expo > PB->expo) {
			appendTerm(C, PA->coef, PA->expo);
			PA = PA->link;
		}
		else {
			appendTerm(C, PB->coef, PB->expo);
			PB = PB->link;
		}
	}
	for (; PA != NULL; PA = PA->link) {
		appendTerm(C, PA->coef, PA->expo);
	}

	for (; PB != NULL; PB = PB->link) {
		appendTerm(C, PB->coef, PB->expo);
	}
}

void printPoly(ListHead* L) {
	ListNode* p = L->head;
	while (p != NULL) {
		printf("% 3.0fx^%d", p->coef, p->expo);
		if (p->link != NULL) printf(" + ");
		p = p->link;
	}

}