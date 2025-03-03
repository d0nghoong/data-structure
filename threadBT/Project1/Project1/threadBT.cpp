#include"threadBT.h"
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
