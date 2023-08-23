#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

typedef struct {
	listNode* head;
}linkList_h;

linkList_h* createdLinkedList(void);
void freeLinkedList_h(linkList_h* L);
void printList(linkList_h* L);
void insertMiddleNode(linkList_h* L, listNode* pre, char* x);
void insertLastNode(linkList_h* L, char* x);
#endif