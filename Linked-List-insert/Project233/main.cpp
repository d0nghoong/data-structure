#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"linkedlist.h"

void main() {
	listNode* p;
	linkList_h* L;
	L = createdLinkedList();

	printf("\n1.���� ����Ʈ �����ϱ�!\n");
	printList(L);

	printf("\n2.����Ʈ�� [��]��� �Է��ϱ�\n");
	insertFirstNode(L, "��");
	printList(L);

	printf("\n3.����Ʈ�� [��]��� Ž���ϱ�\n");
	p = searchNode(L, "��");
	if (p = NULL) printf("ã�� �����Ͱ� �����ϴ�");
	else printf("[%s]�� ã�ҽ��ϴ�", p->data);


	printf("\n4.����Ʈ �������� [��]��� �Է��ϱ�\n");
	insertLastNode(L, "��");
	printList(L);

	printf("\n5.����Ʈ ù��°�� [��]��� �����ϱ�\n");
	insertFirstNode(L, "��");
	printList(L);

	printf("\n6.����Ʈ���� [��]��� �����ϱ�\n");
	p = searchNode(L, "��");
	deleteNode(L, p);
	printList(L);

	printf("\n7. ����Ʈ�� ������ �������� �ٲٱ�");
	reverse(L);
	printList(L);

	printf("\n8.����Ʈ ������ �����Ͽ� ���� ����Ʈ �����\n");
	freeLinkedList_h(L);
	printList(L);

}