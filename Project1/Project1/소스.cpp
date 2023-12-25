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

void insertEdge(graphType* g, int v, int u) {
	if (u >= g->number || v >= g->number) {
		printf("\n그래프에 없는 정점입니다");
		return;
	}
	else {
		graphNode* p;
		p = (graphNode*)malloc(sizeof(graphNode));
		p->vertex = u;
		p->link = g->adjList[v];
		g->adjList[v] = p;
	}
}

void print_adjList(graphType* g) {
	int i;
	graphNode* p;

	for (i = 0; i < g->number; i++) {
		printf("\n정점%C의 연결 리스트", i + 65);
		p = g->adjList[i];
		while (p) {
			printf("->%c", p->vertex + 65);
			p = p->link;
		}
	}
}

int main() {
	int i;
	graphType* G1 = (graphType*)malloc(sizeof(graphType));
	graphType* G2 = (graphType*)malloc(sizeof(graphType));
	graphType* G3 = (graphType*)malloc(sizeof(graphType));
	graphType* G4 = (graphType*)malloc(sizeof(graphType));

	createGraph(G1);
	for (i = 0; i < 4; i++) {
		insertVertex(G1, i);
	}
	insertEdge(G1, 0, 3);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 3, 2);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 3, 0);

	createGraph(G2);
	for (i = 0; i < 3; i++) {
		insertVertex(G2, i);
	}
	insertEdge(G2, 0, 2);
	insertEdge(G2, 0, 1);
	insertEdge(G2, 1, 2);
	insertEdge(G2, 1, 0);
	insertEdge(G2, 2, 1);
	insertEdge(G2, 2, 0);

	createGraph(G3);
	for (i = 0; i < 4; i++) {
		insertVertex(G3, i);
	}
	insertEdge(G3, 0, 3);
	insertEdge(G3, 0, 4);
	insertEdge(G3, 1, 3);
	insertEdge(G3, 1, 2);
	insertEdge(G3, 2, 3);

	createGraph(G4);
	for (i = 0; i < 3; i++) {
		insertVertex(G4, i);
	}
	insertEdge(G4, 0, 2);
	insertEdge(G4, 0, 1);
	insertEdge(G4, 1, 2);
	insertEdge(G4, 1, 0);

	printf("\n\n G1의 인접 리스트");
	print_adjList(G1);

	printf("\n\nG2의 인접 리스트");
	print_adjList(G2);

	printf("\n\nG3의 인접 리스트");
	print_adjList(G3);

	printf("\n\nG4의 인접 리스트");
	print_adjList(G4);
}