#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linkedlist.h"

void deleteNode(linkList_h* L, listNode* p) {
	listNode* pre;
	if (L->head == NULL) return;
	else if (p == NULL) return;
	else {
		pre = L->head;
		while (pre->link != p)
			pre = pre->link;
		pre->link = p->link;
		if (pre != NULL)
			free(p);
	}
}

listNode* searchNode(linkList_h* L, char* x) {
	listNode* p;
	p = L->head;
	while (p != NULL) {
		if (strcmp(p->data, x) == 0) return p;
		else p = p->link;
	}
	return p;
}

void reverse(linkList_h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = L->head;
	q = NULL;
	r = NULL;

	while (p != NULL) {
		q = r;
		r = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}