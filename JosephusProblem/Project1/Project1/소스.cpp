#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct QNode {
	int data;
	struct QNode* rlink;
}QNode;

typedef struct QHead {
	QNode* front, * rear;
}QHead; 

QHead* createQHead();
void enQNode(QHead* QN, element item);
int isQHeadEmpty(QHead* QN);
element deQNode(QHead* QN);

QHead* createQHead() {
	QHead* QN;
	QN = (QHead*)malloc(sizeof(QHead));
	QN->front = NULL;
	QN->rear = NULL;
	return QN;
}

int isQHeadEmpty(QHead* QN) {
	if (QN->front == NULL)
		return 1;
	else return 0;
}

void enQNode(QHead* QN, element item) {
	QNode* newNode;
	newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	if (isQHeadEmpty(QN)) {
		QN->front = newNode;
		QN->rear = newNode;
		newNode->rlink = NULL;
	}
	else {
		QN->rear->rlink = newNode;
		QN->rear = newNode;
	}
}
element deQNode(QHead* QN) {
	if (isQHeadEmpty(QN)) {
		printf("큐가 비었습니다");
		return NULL;
	}
	else {
		QNode* old = QN->front;
		element result = old->data;
		QN->front = QN->front->rlink;
		if (QN->front == NULL) QN->rear = NULL;
		free(old);
		return result;
	}

}


void main() {
	int N, K, t = 0;
	element	i = 1;
	element data;
	QHead* QN = createQHead();
	printf("전체 인원과 추출인원을 입력하십시오: ");
	scanf("%d %d", &N, &K);
	element result[50] = {};
	for (i; i <= N; i++) {
		enQNode(QN, i);
	}
	while (1) {
		for (i = 1; i < K; i++) {
			data = deQNode(QN);
			enQNode(QN, data);
		}
		
		result[t] = deQNode(QN);
		if (t == N-2) break;
		else t += 1;
	}
	for (i = 0; i <N-1; i++) {
		printf("%d ", result[i]);
	}
	printf("%d", deQNode(QN));
	}



