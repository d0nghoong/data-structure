#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUMBER 100
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct treeNode {
	int number;
	char text[MAX_NUMBER];
	treeNode* leftNode;
	treeNode* rightNode;
}treeNode;

void insertNode(treeNode* root, int n,char*text);
treeNode* createNode(int n, char* text);
treeNode* booleanNode(treeNode*root,char a, char b, char c);
void printResult(char* temp,int length);

treeNode* createNode(int n, char* text) {
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->number = n;
	strcpy(newNode->text, text);
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	return newNode;
}

void insertNode(treeNode* root, int n,char*text) {
	if (n < root->number) {
		if (root->leftNode == NULL) {
			root->leftNode = createNode(n, text);
		}
		else  insertNode(root->leftNode, n, text);
	}

	else {
		if (root->rightNode == NULL) {
		root->rightNode = createNode(n, text);
	}
	else
		insertNode(root->rightNode, n,text);
	}
}

treeNode* booleanNode(treeNode* root, char a, char b, char c) {
	treeNode* resultNode = root;

	if (resultNode == NULL) return NULL;
	else {
		if (a == '\0') return resultNode;
		else if (a == 't') resultNode = resultNode->leftNode;
		else resultNode = resultNode->rightNode;
	}

	if (resultNode == NULL) return NULL;
	else {
		if (b == '\0') return resultNode;
		else if (b == 't') resultNode = resultNode->leftNode;
		else resultNode = resultNode->rightNode;
	}

	if (resultNode == NULL) return NULL;
	else {
		if (c == '\0') return resultNode;
		else if (c == 't') resultNode = resultNode->leftNode;
		else resultNode = resultNode->rightNode;
	}

	return resultNode;
}

void printResult(char* temp, int length) {
	if (temp[length - 1] == '?') printf("규칙의 답이 잘못 됨");
	else  printf("결과값: %s", temp);
}


void main() {
	int total;
	int i,n;
	int length;
	char temp[MAX_NUMBER];
	char a1, a2, a3;
	treeNode* rootNode;
	treeNode* tempNode;

	 printf("루트노드의 내용을 입력하세요: ");
    fgets(temp, MAX_NUMBER, stdin);
    temp[strcspn(temp, "\n")] = '\0';  // Remove newline character

    rootNode = createNode(3, temp);

	printf("입력할 노드 갯수를 알려주세요 ");
	scanf("%d", &total);
	getchar();
	
	

	for (i = 0; i < total; i++) {
		printf("노드의 숫자를 입력하세요 ");
		scanf("%d", &n);
		getchar();
		printf("%d번째 노드의 내용을 입력하세요 ", n);
		fgets(temp,MAX_NUMBER,stdin);
        temp[strcspn(temp, "\n")] = '\0';
		insertNode(rootNode, n, temp);
	}

	printf("규칙에 대한 첫번째 답을 입력하시오");
	scanf("%c", &a1);
	getchar();

	printf("규칙에 대한 두번째 답을 입력하시오");
	scanf("%c", &a2);
	getchar();
	
	printf("규칙에 대한 세번째 답을 입력하시오");
	scanf("%c", &a3);
	getchar();

	tempNode= booleanNode(rootNode, a1, a2, a3);
	
	if (tempNode) {
		strcpy(temp, tempNode->text);
		length = strlen(temp);

		printResult(temp, length);
	}
	else {
		printf("오류 발생");
	}

}

