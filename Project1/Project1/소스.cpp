#define _CRT_SECURE_NO_WARNINGS
#define Q_SIZE 4
typedef char element;

#include<stdio.h>
#include<stdlib.h>

typedef struct QueueType {
	element queue[Q_SIZE];
	int front, rear;
}QueueType;

QueueType* createQueue(void);
int isQueueEmpty(QueueType* Q);
int isQueueFull(QueueType* Q);
void enQueue(QueueType* Q, element data);
element deQueue(QueueType* Q);
element peek(QueueType* Q);
void print(QueueType* Q);

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

int main() {
	QueueType* Q1 = createQueue();
	element data;
	printf("\n***** 순차 큐 연산 *****\n");
	printf("\n삽입 A>>>"); enQueue(Q1, 'A'); print(Q1);
	printf("\n삽입 B>>>"); enQueue(Q1, 'B'); print(Q1);
	printf("\n삽입 C>>>"); enQueue(Q1, 'C'); print(Q1);
	data = peek(Q1); printf("\tpeek item: %c", data);
	printf("\n삭제>>>"); data = deQueue(Q1); print(Q1);  printf("\t삭제데이터:%c", data);
	printf("\n삭제>>>"); data = deQueue(Q1); print(Q1);  printf("\t삭제데이터:%c", data);
	printf("\n삭제>>>"); data = deQueue(Q1); print(Q1);  printf("\t삭제데이터:%c", data);

	printf("\n삽입 D>>>"); enQueue(Q1, 'D'); print(Q1);
	printf("\n삽입 E>>>"); enQueue(Q1, 'E'); print(Q1);

}