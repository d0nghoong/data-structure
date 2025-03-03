#pragma once
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