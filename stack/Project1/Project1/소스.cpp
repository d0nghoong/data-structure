#define STACK_SIZE 100
#include<stdio.h>

typedef int element;
element stack[STACK_SIZE];

int top = -1;

int isStackEmpty();
int isStackFull();
void push(element item);
element pop();
element peek();
void printStack();

int isStackEmpty() {
	if (top == -1) return 1;
	else return 0;

}

int isStackFull() {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

void push(element item) {
	if (isStackFull()) {
		printf("stack is full");
		return;
	}
	else stack[++top] = item;

}

element pop() {
	if (isStackEmpty()) {
		printf("stack is empty");
		return 0;
	}
	else return stack[top--];
}

element peek() {
	if (isStackEmpty()) {
		printf("stack is empty");
		return 0;
	}
	else return stack[top];
}

void printStack() {
	int p;
	printf("\nstack [");
	for (p = 0; p <= top; p++) {
		printf("%d ", stack[p]);
	}
	printf("]");
}

void main() {
	element item;
	printf("\n** 순차 스택 연산**\n");
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	printf("\t peek=> %d", item);
	
	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);
}