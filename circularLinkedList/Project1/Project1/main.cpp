#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "CircularLinkedList.h"
void main() {
	linkedList_h* CL;
	listNode* p;

	CL = createdLinkedList_h();
	printf("(1) ��������Ʈ �����ϱ�\n");
	printList(CL);

	printf("\n(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�!\n");
	InsertFirstNode(CL, "��");
	printList(CL);

	printf("\n(3) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�\n");
	p = searchNode(CL, "��");
	InsertMiddleNode(CL, p, "��");
	printList(CL);

	printf("\n(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�\n");
	p = searchNode(CL, "��");
	InsertMiddleNode(CL, p, "��");
	printList(CL);

	printf("\n (5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�");
	p = searchNode(CL, "��");
	deleteNode(CL, p);
	printList(CL);
}
