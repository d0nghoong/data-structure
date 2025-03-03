#define _CRT_SECURE_NO_WARNINGS
#define element int
#define MAX_VERTEX 30
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include<stdlib.h>


typedef struct stackNode {
	element number;
	struct stackNode* link;
}stackNode;

stackNode* top;

void push(int v);
element pop();
int isStackEmpty();

int isStackEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

void push(int v) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->number = v;
	temp->link = top;
	top = temp;
}

element pop() {
	int i = top->number;
	top = top->link;
	return i;
}

typedef struct graphNode {
	element vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n;
	graphNode* adjList[MAX_VERTEX];
	int visited[MAX_VERTEX];
}graphType;

void creategraphType(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjList(graphType* g);
void DFS_adjList(graphType* g,int v);

void creategraphType(graphType* g) {
	int i = 0;
	g->n = 0;
	for (i; i < MAX_VERTEX; i++) {
		g->adjList[i] = NULL;
		g->visited[i] = FALSE;
	}
}

void insertVertex(graphType* g, int v) {
	if ((v + 1) > MAX_VERTEX) {
		printf("정점이 모두 찼습니다");
		return;
	}
	else {
		g->n++;
	}
}

void insertEdge(graphType* g, int u, int v) {
	int i;
	if (u >= g->n || v >= g->n) {
		printf("존재하지 않는 정점입니다");
		return;
	}
	else {
			graphNode* temp;
			temp = (graphNode*)malloc(sizeof(graphNode));
			temp->link = g->adjList[u];
			temp->vertex = v;
			g->adjList[u] = temp;
		}
	}

void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		p = g->adjList[i];
		printf("\n정점 %c의 연결 리스트", i + 65);
		while (p) {
			printf("->%c", p->vertex+65);
			p = p->link;
		}
	}
}

void DFS_adjList(graphType* g,int v) {
	graphNode* p;
	push(v);
	g->visited[v] = TRUE;
	printf("%c ", v+65);
	while (!isStackEmpty()) {
		p = g->adjList[v];
		while (p) {
			if (!g->visited[p->vertex]) {
				push(p->vertex);
				g->visited[p->vertex] = TRUE;
				printf("%c ", p->vertex + 65);
				v = p->vertex;
				p = g->adjList[v];
			}
			p = p->link;
		}
		v=pop();
	}

}

int main() {
	int i;
	graphType* G9;
	G9 = (graphType*)malloc(sizeof(graphType));
	creategraphType(G9);
	for (i = 0; i < 7; i++) {
		insertVertex(G9, i);
	}
	insertEdge(G9, 0, 2);
	insertEdge(G9, 0, 1);
	insertEdge(G9, 1, 4);
	insertEdge(G9, 1, 3);
	insertEdge(G9, 1, 0);
	insertEdge(G9, 2, 4);
	insertEdge(G9, 2, 2);
	insertEdge(G9, 3, 6);
	insertEdge(G9, 3, 1);
	insertEdge(G9, 4, 6);
	insertEdge(G9, 4, 2);
	insertEdge(G9, 4, 1);
	insertEdge(G9, 5, 6);
	insertEdge(G9, 6, 5);
	insertEdge(G9, 6, 4);
	insertEdge(G9, 6, 3);
	printf("\nG9의 인접 리스트");
	print_adjList(G9);
	printf("\n깊이 우선 탐색");
	DFS_adjList(G9, 0);
}
   