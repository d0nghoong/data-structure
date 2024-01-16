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
		p->end=newNode;
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
		p->visited[i] = FALSE;
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

void BfsFunction(adjList* p, int n, queueHead* q) {
	int w;
	adjNode* v;
	enQueue(q, n);
	printf("%c\n", n + 65);
	p->visited[n] = TRUE;
	while (!isQueueEmpty(q)) {
		w = deQueue(q);
		for (v = p->adjArray[w]; v; v=v->link) {
			if (!p->visited[v->value]) {
				enQueue(q, v->value);
				printf("%c\n", v->value + 65);
				p->visited[v->value] = TRUE;
			}
		}
	}
}

	void main(){
		int i;
		adjList* G9;
		queueHead* q;
		G9 = createList();

		for (i = 0; i < 7; i++)
			increaseNode(G9);

		insertEdge(G9, 0, 2);
		insertEdge(G9, 0, 1);
		insertEdge(G9, 1, 4);
		insertEdge(G9, 1, 3);
		insertEdge(G9, 1, 0);
		insertEdge(G9, 2, 4);
		insertEdge(G9, 2, 0);
		insertEdge(G9, 3, 6);
		insertEdge(G9, 3, 1);
		insertEdge(G9, 4, 6);
		insertEdge(G9, 4, 2);
		insertEdge(G9, 4, 1);
		insertEdge(G9, 5, 6);
		insertEdge(G9, 6, 5);
		insertEdge(G9, 6, 4);
		insertEdge(G9, 6, 3);

		q = createQueue();
		BfsFunction(G9, 0, q);
		
	}
