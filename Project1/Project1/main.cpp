#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "myPlaylist.h"

void main() {
	ListCircularHead* M;
	ListHead* L;

	M = createCircularNode();
	L = createLinkedNode();

	int n;
	char name;
	while (1) {
		printf("1.�뷡 �߰��ϱ� 2.�ݺ� ��� ����� 3.�ߴ�\n");
		scanf_s("%d", &n);
		getchar();
		if (n == 1) {
			printf("�뷡 ������ �ۼ��Ͻÿ�\n");
			scanf_s("%c", &name);
			getchar();
			addNode(L, name);
			printList(L);
		}
		else if (n == 2) {
			printf("�ݺ� ����� �뷡�� �����Ͻÿ�\n");
			scanf_s("%c", &name);
			getchar();
			selectList(L, M, name);
			printCircularList(M);
		}
		else if (n == 3) break;
		else {
			printf("�߸��� �Է��Դϴ�");
		}
		printf("\n");
	}

}