#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int folderSize=0;

typedef int element;
typedef struct treeNode {
	int size;
	struct treeNode* leftNode;
	struct treeNode* rightNode;
}treeNode;

treeNode* createNode(element item, treeNode* leftNode, treeNode* rightNode);
int postorder_FolderSize(treeNode* root);

treeNode* createNode(element item, treeNode* leftNode, treeNode* rightNode) {
	treeNode* newNode;
	newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->size = item;
	newNode->leftNode = leftNode;
	newNode->rightNode = rightNode;

	return newNode;
}

int postorder_FolderSize(treeNode* root) {
	if (root) {
		postorder_FolderSize(root->leftNode);
		postorder_FolderSize(root->rightNode);
		folderSize += root->size;
	}
	return folderSize;
}

void main() {
	treeNode* f11 = createNode(120, NULL, NULL);
	treeNode* f10 = createNode(55, NULL, NULL);
	treeNode* f9 = createNode(100, NULL, NULL);
	treeNode* f8 = createNode(200, NULL, NULL);
	treeNode* f7 = createNode(68, f10, f11);
	treeNode* f6 = createNode(40, NULL, NULL);
	treeNode* f5 = createNode(15, NULL, NULL);
	treeNode* f4 = createNode(2, f8, f9);
	treeNode* f3 = createNode(10, f6, f7);
	treeNode* f2 = createNode(0, f4, f5);
	treeNode* f1 = createNode(0, f2, f3);

	printf("\n\nc:\\의 용량: %d M\n", postorder_FolderSize(f2));
	folderSize = 0;
	printf("\nD:\\의 용량: %d M\n", postorder_FolderSize(f3));
	folderSize = 0;
	printf("\n전체 용량: %d M\n", postorder_FolderSize(f1));
}