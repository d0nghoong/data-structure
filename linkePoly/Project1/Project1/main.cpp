#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"LinkedPoly.h"



void main() {
	ListHead* A, * B, * C;
	A = createLinkedList();
	B = createLinkedList();
	C = createLinkedList();

	appendTerm(A, 4, 3);
	appendTerm(A, 3, 2);
	appendTerm(A, 5, 1);
	printf("A(x)= ");
	printPoly(A);

	appendTerm(B, 3, 4);
	appendTerm(B, 1, 3);
	appendTerm(B, 2, 1);
	appendTerm(B, 1, 0);
	printf("\nB(x)= ");
	printPoly(B);

	addPoly(A, B, C);
	printf("\nC(x)= ");
	printPoly(C);
}
