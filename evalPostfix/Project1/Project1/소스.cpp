#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;



typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top = NULL;
element evalPostfix(char* exp);
element pop();
void push(element value);
int isStackEmpty();

int isStackEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

element pop() {
	if (isStackEmpty()) {
		return 0;
	}
	else {
		element result = top->data;
		top = top->link;

		return(result);
	}
}

void push(element value) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = value;
	temp->link = top;
	top = temp;
}

element evalPostfix(char* exp) {
	int op1, op2, value, i = 0;
	char symbol;
	int length = strlen(exp);
	for (i; i < length; i++) {
		symbol = exp[i];
		if ((symbol != '+') && (symbol != '-') && (symbol != '*') && (symbol != '/')) {
			value = symbol - '0';
			push(value);
		}
		else {
			op1 = pop();
			op2 = pop();
			switch (symbol) {
			case '+': push(op1 + op2); break;
			case '-': push(op2 - op1); break;
			case '*': push(op1 * op2); break;
			case'/':push(op2 / op1); break;
			}
		}
	}
	return pop();
}

int main() {
	int result;
	char* express = "35*62/-";
	printf("후위 표기식: %s", express);
	result = evalPostfix(express);
	printf("\n연산 결과값=>%d", result);
}