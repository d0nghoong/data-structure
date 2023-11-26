#pragma once
#define _Crt_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct treeNode {
	char data;
	struct treeNode* leftNode;
	struct treeNode* rightNode;
	int isThreadRight;
}treeNode;

treeNode* createNode(element item, treeNode* left, treeNode* right, int isThreadRight);
treeNode* findThreadSuccessor(treeNode* q);
void threadinorder(treeNode* root);