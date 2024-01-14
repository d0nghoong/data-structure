#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define INF 1000
#define MAX_VERTICES 5

#include<stdio.h>

int distance[MAX_VERTICES];
int S[MAX_VERTICES];

int weight[MAX_VERTICES][MAX_VERTICES] = {
	{0,10,5,INF,INF},
	{INF,0,2,1,INF},
	{INF,3,0,9,2},
	{INF,INF,INF,0,4},
	{7,INF,INF,6,0}
};


int nextVertex();
int printStep(int step);
void Dijkstra_shortestPath(int start, int n);

int nextVertex() {
	int i, min, minPos;
	min = INF;
	minPos = -1;

	for (i = 0; i < MAX_VERTICES; i++) {
		if (distance[i] < min && !S[i]) {
			min = distance[i];
			minPos = i;
		}
	}
	return minPos;
}

int printStep(int step) {
	int i;
	printf("\n%d 단계: ", step);
	printf("S={");
	for (i = 0; i < MAX_VERTICES; i++) {
		if (S[i] == TRUE) printf("%3c", i + 65);
	}
	printf("}");
	if (step < 1) printf("\t\t\t");
	else if (step < 3)printf("\t\t");
	else printf("\t");

	printf("distance:[ ");
	for (i = 0; i < MAX_VERTICES; i++) {
		if (distance[i] == INF)
			printf("%4c", '*');
		else printf("%4d ", distance[i]);
	}
	printf("]");
	return ++step;
}

void Dijkstra_shortestPath(int start, int n) {
	int i, v,w;
	int step = 0;
	for (i = 0; i < MAX_VERTICES; i++) {
		S[i] = FALSE;
		distance[i] = weight[start][i];
	}
	step = printStep(step);

	S[start] = TRUE;
	distance[start] = 0;

	for (i = 0; i < n - 1; i++) {
		v = nextVertex();
		S[v] = TRUE;
		for (w = 0; w < n; w++) {
			if (!S[w]) {
				if (distance[v] + weight[v][w] < distance[w])
					distance[w] = distance[v] + weight[v][w];
			}
		}
		step = printStep(step);
	}
}

int main() {
	int i, j;
	printf("********** 가중치 인접 행렬 **********\n");
	for (i = 0; i < MAX_VERTICES; i++) {
		for (j = 0; j < MAX_VERTICES; j++) {
			if (weight[i][j] == INF)
				printf("%4c", '*');
			else printf("%4d", weight[i][j]);
		}
		printf("\n\n");
	}

	printf("\n ********** 다익스트라 최단 경로 구하기 ***********");
	Dijkstra_shortestPath(0, MAX_VERTICES);
}