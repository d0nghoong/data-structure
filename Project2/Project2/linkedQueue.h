#pragma once
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
