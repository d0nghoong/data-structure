#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct stackNode{
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top=NULL;

int isStackEmpty();
void push(element item);
element pop();
element peek();
void printStack();

int isStackEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

void push(element item) {
	stackNode* newNode;
	newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = item;
	newNode->link = top;
	top = newNode;
}

element pop() {
	element item;
	stackNode* temp = top;
	if (isStackEmpty()) {
		printf("\n스택이 비었으예\n");
		return 0;
	}
	else {
		item = top->data;
		top = top->link;
		free(temp);
		return item;
	}
}

element peek() {
	if (isStackEmpty()) {
		printf("\n스택이 비었으예\n");
		return 0;
	}
	else return(top->data);
}

void printStack() {
	stackNode* p;
	printf("\nSTACK [");
	p = top;
	while (p) {
		printf("%d ",p->data);
		p = p->link;
	}
	printf("]");

}
void main() {
	element item;

	printf("\n**연결 스택 연산**\n");
	printStack();
	
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	printf("\t peek=>%d", item);
	
	item = pop(); printStack();
	printf("\t pop=>%d", item);

	item = pop(); printStack();
	printf("\t pop=>%d", item);

	item = pop(); printStack();
	printf("\t pop=>%d", item);
}
