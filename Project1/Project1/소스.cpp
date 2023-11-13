#define _CRT_SECURE_NO_WARNINGS
#define CQ_SIZE 4
#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct QueueType {
	element queue[CQ_SIZE];
	int front, rear;
}QueueType;

QueueType* createCqueue(void);
int isCqueueEmpty(QueueType* q);
int isCqueueFull(QueueType* q);
void enCqueue(QueueType* q, element item);
element deCequeue(QueueType* q);
element peek(QueueType* q);
void printCq(QueueType* q);

QueueType* createCqueue(void) {
	QueueType* q;
	q = (QueueType*)malloc(sizeof(QueueType));
	q->front = 0;
	q->rear = 0;
	return q;
}

int isCqueueEmpty(QueueType* q) {
	if (q->front == q->rear) {
		printf("Cqueue is empty");
		return 1;
	}
	else return 0;
}

int isCqueueFULL(QueueType* q) {
	if (((q->rear + 1) % CQ_SIZE) == q->front) {
		printf("Cqueue is full");
		return 1;
	}
	else return 0;
}

void enCqueue(QueueType* q, element item) {
	if (isCqueueFULL(q)) return;
	else {
		q->rear = (q->rear + 1) % CQ_SIZE;
		q->queue[q->rear] = item;
	}
}

element deCequeue(QueueType* q) {
	if (isCqueueEmpty(q)) return NULL;
	else {
		q->front = (q->front + 1) % CQ_SIZE;
		return q->queue[q->front];
	}
}

element peek(QueueType* q) {
	if (isCqueueEmpty(q)) return NULL;
	else return q->queue[(q->front + 1) % CQ_SIZE];
}
void printCq(QueueType* q) {
	int i,first, last;
	first = (q->front+1)%CQ_SIZE;
	last = q->rear;
	i = first;
	
	printf("Cqueue=[ ");
	while (i != last) {
		printf("%3c", q->queue[i]);
		printf(",");
		i = (i + 1) % CQ_SIZE;
	}
	printf("%3c", q->queue[i]);
	printf("]");
}

void main(void) {
	QueueType* cQ = createCqueue();
	element data;
	printf("\n***** 원형 큐 연산 *****\n");
	printf("\n삽입 A>>"); enCqueue(cQ, 'A'); printCq(cQ);
	printf("\n삽입 B>>"); enCqueue(cQ, 'B'); printCq(cQ);
	printf("\n삽입 C>>"); enCqueue(cQ, 'C'); printCq(cQ);
	data = peek(cQ); printf("peek item: %c\n", data);
	printf("\n삭제>>"); data = deCequeue(cQ); printCq(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n삭제>>"); data = deCequeue(cQ); printCq(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n삭제>>"); data = deCequeue(cQ); printCq(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n삽입 D>>"); enCqueue(cQ, 'D'); printCq(cQ);
	printf("\n삽입 E>>"); enCqueue(cQ, 'E'); printCq(cQ);
}




