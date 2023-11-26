#include"threadBT.h"
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

