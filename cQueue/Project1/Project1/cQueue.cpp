#include "cQueue.h"

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
	int i, first, last;
	first = (q->front + 1) % CQ_SIZE;
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