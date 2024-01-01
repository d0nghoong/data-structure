#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUMBER 100
#define TRUE 1
#define FALSE 0

#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct queueNode {
	element text;
	queueNode* link;
}queueNode;

typedef struct queueHead {
	queueNode* start, * end;
}queueHead;

queueHead* createQueue();
void enQueue(queueHead* p, element i);
element deQueue(queueHead* p);
int isQueueEmpty(queueHead* p);

int isQueueEmpty(queueHead* p) {
	if (p->start == NULL) return 1;
	else return 0;
}
queueHead* createQueue() {
	queueHead* p = (queueHead*)malloc(sizeof(queueHead));
	p->start = NULL;
	p->end = NULL;
	return p;
}

void enQueue(queueHead* p, element i) {
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->text = i;
	newNode->link = NULL;
	if (isQueueEmpty(p)) {
		p->start = newNode;
		p->end = newNode;
	}
	else {
		p->end->link = newNode;
		newNode = p->end;
	}
	}

element deQueue(queueHead* p) {
	element value = p->start->text;
	if (isQueueEmpty(p)) {
		printf("Queue가 비었습니다");
		return 0;
	}
	else {
		p->start = p->start->link;
		return value;
	}
}

typedef struct adjNode {
	element value;
	adjNode* link;
}adjNode;

typedef struct adjList {
	int length;
	adjNode* adjArray[MAX_NUMBER];
	int visited[MAX_NUMBER];
}adjList;

adjList* createList();
void increaseNode(adjList* p);
void insertEdge(adjList* p, element v, element u);

adjList* createList() {
	int i;
	adjList* p = (adjList*)malloc(sizeof(adjList));
	p->length = 0;
	for (i = 0; i < MAX_NUMBER; i++) {
		p->adjArray[i] = NULL;
		p->visited[i] = 0;
	}
	return p;
}

void increaseNode(adjList* p) {
	if ((p->length + 1) > MAX_NUMBER) printf("노드가 다 찼습니다");
	else {
		p->length++;
	}
}

void insertEdge(adjList* p, element v, element u) {
	if (v > p->length || u > p->length) {
		printf("존재하지 않는 노드입니다");
	}
	else {
		adjNode* newNode = (adjNode*)malloc(sizeof(newNode));
		newNode->value = u;
		newNode->link = p->adjArray[v];
		p->adjArray[v] = newNode;
	}
}
