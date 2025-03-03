#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;

typedef struct Node {
	char data;
	struct Node* link;
}Node;

Node* top= NULL;

int isStackEmpty();
void push(element item);
element pop();
element peek();
int testPair(char*exp);

int isStackEmpty() {
	if (top == NULL) {
		return 1;
	}
	else return 0;
}
void push(element item) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	newNode->link = top;
	top = newNode;
}

element pop() {
	if (isStackEmpty()) {
		printf("스택이 비었습니다");
		return 0;
	}
	Node* temp;
	temp = top;
	top = top->link;
	return(temp->data);
	free(temp);
}

element peek() {
	if (isStackEmpty()) {
		printf("스택이 비었습니다");
		return 0;
	}
	return(top->data);
}

int testPair(char*exp) {
	char symbol,result	;
	int i, length = strlen(exp);

	for (i = 0; i < length; i++) {
		symbol = exp[i];

		switch (symbol) {
		case '(':
		case '{':
		case '[':
		push(symbol);
		break;
		
		case ')':
		case '}':
		case ']':
		if (isStackEmpty()) return 0;
		result = pop();
		if ((symbol == ')' && result == '(' || (symbol == '}' && result == '{') || (symbol == ']' && result == '[')
			))
		
			break;
		else
			return 0;
		}
	}
	if (top == NULL) return 1;
	else return 0;
}

void main() {
	char* express = "{(A+B)-3}*5+[{cos(x+y)+7-1}]*4";
	printf("%s", express);

	if (testPair(express) == 1)
		printf("\n 수식의 괄호가 맞게 사용 되었습니다");
	else
		printf("\n 수식의 괄호가 잘못 되었습니다");
}


