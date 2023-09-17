#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

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
void selectList(ListHead* L, ListHead* M, char name);
void printCircularList(ListCircularHead* M);
void printList(ListHead* L);

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


void main() {
	ListCircularHead* M;
	ListHead* L;
	
	M = createCircularNode();
	L = createLinkedNode();

	int n;
	char name;
	 while(1){
		printf("1.노래 추가하기 2.반복 재생 만들기 3.중단\n");
		scanf_s("%d", &n);
		getchar();
		if (n == 1) {
			printf("노래 제목을 작성하시오\n");
			scanf_s("%c", &name);
			getchar();
			addNode(L,name);
			printList(L);
		}
		else if (n == 2) {
			printf("반복 재생할 노래를 선택하시오\n");
			scanf_s("%c", &name);
			getchar();
			selectList(L, M, name);
			printCircularList(M);
		}
		else if (n == 3) break;
		else {
			printf("잘못된 입력입니다");
		}
		printf("\n");
	}

}
