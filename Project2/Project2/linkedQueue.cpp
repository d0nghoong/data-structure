#include "linkedQueue.h"
LQueueType* createLinkedQueue() {
	LQueueType* newNode;
	newNode = (LQueueType*)malloc(sizeof(LQueueType));
	newNode->front = NULL;
	newNode->rear = NULL;
	return newNode;
}

int isLQEmpty(LQueueType* lq) {
	if (lq->front == NULL) {
		printf("Queue is empty");
		return 1;
	}
	else return 0;
}

void enLQueue(LQueueType* lq, element item) {
	QNode* newNode;
	newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (lq->front == NULL) {
		lq->front = newNode;
		lq->rear = newNode;
	}
	else {
		lq->rear->link = newNode;
		lq->rear = newNode;
	}
}

element deLQueue(LQueueType* lq) {
	if (isLQEmpty(lq)) return NULL;
	else {
		QNode* old = lq->front;
		element item;
		item = lq->front->data;
		lq->front = lq->front->link;
		free(old);
		if (lq->front == NULL)lq->rear = NULL;
		return item;
	}
}

element peek(LQueueType* lq) {
	if (isLQEmpty(lq)) return NULL;
	else return(lq->front->data);
}

void print(LQueueType* lq) {
	if (isLQEmpty(lq)) return;
	QNode* temp;
	temp = lq->front;
	printf(" LinkedQueue: [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf("]");
}
