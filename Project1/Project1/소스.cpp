#define MAX_VERTEX 30
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int number;
	graphNode* adjList[MAX_VERTEX];
}graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int v, int u);
void print_adjList(graphType* g);

void createGraph(graphType* g) {
	g->number = 0;
	for (int v = 0; v < MAX_VERTEX; v++) {
		g->adjList[v] = 0;
	}
}

void insertVertex(graphType* g, int v) {
	if ((v + 1) > MAX_VERTEX) {
		printf("\n그래프 정점 개수를 초과하였습니다");
			return;
	}
	else {
		g->number++;
	}
}
