#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"DoubleLinkedList.h"

void main() {
	linkedList_h* DL;
	listNode* p;

	printf("(1) ���� ���� ����Ʈ �����ϱ�\n");
	DL = createdLinkedList_h();
	printList(DL);

	printf("\n(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�\n");
	insertNode(DL, NULL, "��");
	printList(DL);

	printf("\n(3) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�\n");
	p = searchNode(DL, "��");
	insertNode(DL, p, "��");
	printList(DL);

	printf("\n(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�\n");
	p = searchNode(DL, "��");
	insertNode(DL, p, "��");
	printList(DL);

	printf("\n(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�\n");
	p = searchNode(DL, "��");
	deleteNode(DL, p);
	printList(DL);



}