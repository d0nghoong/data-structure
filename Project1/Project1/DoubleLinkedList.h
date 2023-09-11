#pragma once
typedef struct ListNode {
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
}listNode;

typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createdLinkedList_h();
void printList(linkedList_h* DL);
void insertNode(linkedList_h* DL, listNode* pre, char* x);
void deleteNode(linkedList_h* DL, listNode* old);
listNode* searchNode(linkedList_h* DL, char* x);



