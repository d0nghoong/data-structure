#include"queueS.h"

QueueType* createQueue(void) {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1; Q->rear = -1;
	return Q;
}

int isQueueEmpty(QueueType* Q) {
	if (Q->front == Q->rear) {
		printf("Queue is Empty");
		return 1;
	}
	return 0;
}

int isQueueFull(QueueType* Q) {
	if (Q->rear == Q_SIZE - 1) {
		printf("Queue is FULL");
		return 1;
	}
	return 0;
}

void enQueue(QueueType* Q, element data) {
	if (isQueueFull(Q)) {
		return;
	}
	Q->rear++;
	Q->queue[Q->rear] = data;
}

element deQueue(QueueType* Q) {
	if (isQueueEmpty(Q)) {
		return 0;
	}
	Q->front++;
	return Q->queue[Q->front];
}

element peek(QueueType* Q) {
	if (isQueueEmpty(Q)) {
		return 0;
	}
	return Q->queue[Q->front + 1];
}

void print(QueueType* Q) {
	int i;
	printf("Q=[");
	for (i = Q->front + 1; i <= Q->rear; i++) {
		printf(" %c,", Q->queue[i]);
	}
	printf("]");
}