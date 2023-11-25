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

treeNode* createNode(element item, treeNode* left, treeNode* right, int isThreadRight) {
	treeNode* newNode;
	newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->data = item;
	newNode->leftNode = left;
	newNode->rightNode = right;
	newNode->isThreadRight = isThreadRight;

	return newNode;
}

treeNode* findThreadSuccessor(treeNode* q) {
	treeNode* p;
	p = q->rightNode;
	if (p == NULL) return p;
	if (q->isThreadRight == 1) return p;
	while (p->leftNode != NULL)p = p->leftNode;
	return p;
}

void threadinorder(treeNode* root) {
	treeNode* q = root;
	while (q->leftNode) q = q->leftNode;
	do {
		printf("%c", q->data);
		q = findThreadSuccessor(q);
	} while (q);
}

void main() {
	treeNode* n7 = createNode('D', NULL, NULL, 0);
	treeNode* n6 = createNode('C', NULL, NULL, 1);
	treeNode* n5 = createNode('B', NULL, NULL, 1);
	treeNode* n4 = createNode('A', NULL, NULL, 1);
	treeNode* n3 = createNode('/', n6, n7, 0);
	treeNode* n2 = createNode('*', n4, n5, 0);
	treeNode* n1 = createNode('-',n2, n3, 0);

	n6->rightNode = n3;
	n5->rightNode = n1;
	n4->rightNode = n2;

	printf("스레드 이진 트리의 중위 순회: ");
	threadinorder(n1);
}

