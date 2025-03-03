#define _CRT_SECURE_NO_WARNINGS
#define INF 10000
#define MAX_VERTICES 5
#include<stdio.h>

int A[MAX_VERTICES][MAX_VERTICES];

int weight[MAX_VERTICES][MAX_VERTICES] = {
	{0,10,5,INF,INF},
	{INF,0,2,1,INF},
	{INF,3,0,9,2},
	{INF,INF,INF,0,4},
	{7,INF,INF,6,0}
};

void printStep(int step);
void floydFunction();

void printStep(int step) {
	int v, w;
	printf("A%d", step);

	for (v = 0; v < MAX_VERTICES; v++) {
		printf("\t");
		for (w = 0; w < MAX_VERTICES; w++) {
			if (A[v][w] == INF) printf("%4c", '*');
			else printf("%4d", A[v][w]);
		}
		printf("\n");
	}
}
void floydFunction() {
	int step = -1;
	int i, j, k;
	for (i = 0; i < MAX_VERTICES; i++)
	{
		for (j = 0; j < MAX_VERTICES; j++)
			A[i][j] = weight[i][j];
	}
	printStep(step);
	for (k = 0; k < MAX_VERTICES; k++)
	{
		for (i = 0; i < MAX_VERTICES; i++) {
			for (j = 0; j < MAX_VERTICES; j++) {
				if (A[i][j] > A[i][k] + A[k][j]) A[i][j] = A[i][k] + A[k][j];
			}
		}
		printStep(++step);
	}
}

void main() {
	int i, j;
	printf("********** 가중치 인접 행렬 ***********");
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF) printf("%4c", '*');
			else printf("%4d", weight[i][j]);
		}
		printf("\n");
	}

	printf("\n**********플로이드 최단 경로 구하기 **********");
	floydFunction();
}