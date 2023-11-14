#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct QNode {
	element data;
	struct QNode* link;
}QNode;

typedef struct LQueueType {
	QNode* front, * rear;
}LQueueType;

LQueueType* createLinkedQueue(void);
int isLQEmpty(LQueueType* lq);
void enLQueue(LQueueType* lq, element item);
element deLQueue(LQueueType* lq);
element peek(LQueueType* lq);
void print(LQueueType* lq);

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

int main() {
	LQueueType* LQ = createLinkedQueue();
	element data;
	printf("\n 삽입 A>>"); enLQueue(LQ, 'A'); print(LQ);
	printf("\n 삽입 B>>"); enLQueue(LQ, 'B'); print(LQ);
	printf("\n 삽입 C>>"); enLQueue(LQ, 'C'); print(LQ);
	data = peek(LQ); printf("peek item: %c\n", data);
	printf("\n삭제>>"); data = deLQueue(LQ); print(LQ);
	printf("\t삭제 데이터:%c", data);
	printf("\n삭제>>"); data = deLQueue(LQ); print(LQ);
	printf("\t삭제 데이터:%c", data);
	printf("\n삭제>>"); data = deLQueue(LQ); print(LQ);
	printf("\t삭제 데이터:%c", data);
}