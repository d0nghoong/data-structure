#pragma once
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
