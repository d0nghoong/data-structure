#pragma once
typedef struct ListNode {
	char name;
	struct ListNode* link;
}ListNode;

typedef struct ListCircularNode {
	char name;
	struct ListCircularNode* llink;
	struct ListCircularNode* rlink;

}ListCircularNode;

typedef struct {
	ListNode* head;
}ListHead;

typedef struct {
	ListCircularNode* head;
}ListCircularHead;

ListHead* createLinkedNode();
ListCircularHead* createCircularNode();
void addNode(ListHead* L, char name);
void addCircularNode(ListCircularHead* L, char name);
void selectList(ListHead* L, ListCircularHead* M, char name);
void printCircularList(ListCircularHead* M);
void printList(ListHead* L);
