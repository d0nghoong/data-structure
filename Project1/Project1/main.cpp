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
		printf("1.노래 추가하기 2.반복 재생 만들기 3.중단\n");
		scanf_s("%d", &n);
		getchar();
		if (n == 1) {
			printf("노래 제목을 작성하시오\n");
			scanf_s("%c", &name);
			getchar();
			addNode(L, name);
			printList(L);
		}
		else if (n == 2) {
			printf("반복 재생할 노래를 선택하시오\n");
			scanf_s("%c", &name);
			getchar();
			selectList(L, M, name);
			printCircularList(M);
		}
		else if (n == 3) break;
		else {
			printf("잘못된 입력입니다");
		}
		printf("\n");
	}

}