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
	if (temp[length - 1] == '?') printf("��Ģ�� ���� �߸� ��");
	else  printf("�����: %s", temp);
}


void main() {
	int total;
	int i,n;
	int length;
	char temp[MAX_NUMBER];
	char a1, a2, a3;
	treeNode* rootNode;
	treeNode* tempNode;

	 printf("��Ʈ����� ������ �Է��ϼ���: ");
    fgets(temp, MAX_NUMBER, stdin);
    temp[strcspn(temp, "\n")] = '\0';  // Remove newline character

    rootNode = createNode(3, temp);

	printf("�Է��� ��� ������ �˷��ּ��� ");
	scanf("%d", &total);
	getchar();
	
	

	for (i = 0; i < total; i++) {
		printf("����� ���ڸ� �Է��ϼ��� ");
		scanf("%d", &n);
		getchar();
		printf("%d��° ����� ������ �Է��ϼ��� ", n);
		fgets(temp,MAX_NUMBER,stdin);
        temp[strcspn(temp, "\n")] = '\0';
		insertNode(rootNode, n, temp);
	}

	printf("��Ģ�� ���� ù��° ���� �Է��Ͻÿ�");
	scanf("%c", &a1);
	getchar();

	printf("��Ģ�� ���� �ι�° ���� �Է��Ͻÿ�");
	scanf("%c", &a2);
	getchar();
	
	printf("��Ģ�� ���� ����° ���� �Է��Ͻÿ�");
	scanf("%c", &a3);
	getchar();

	tempNode= booleanNode(rootNode, a1, a2, a3);
	
	if (tempNode) {
		strcpy(temp, tempNode->text);
		length = strlen(temp);

		printResult(temp, length);
	}
	else {
		printf("���� �߻�");
	}

}

