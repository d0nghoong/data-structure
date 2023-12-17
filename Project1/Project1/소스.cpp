#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENT 100

#include<stdio.h>
#include<stdlib.h>

typedef struct heapType {
	int heap[MAX_ELEMENT];
	int heap_size;
}heapType;

heapType* createHeapType();
void inserHeapType(heapType* h, int item);
int deleteHeapType(heapType* h);
void printHeap(heapType* h);

heapType* createHeapType() {
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

void insertHeapType(heapType* h, int item) {
	h->heap_size += 1;
	int i = h->heap_size;

		while ((i != 1) && (item > h->heap[i / 2])) {
			h->heap[i] = h->heap[i / 2];
			i = i / 2;
		}

	h->heap[i] = item;
}

int deleteHeapType(heapType* h) {
	int parent, child;
	int item = h->heap[h->heap_size];
	parent = 1; child = 2;
	h->heap_size -= 1;
	while(child <= h->heap_size) {
		if ((child < h->heap_size) && h->heap[child] < h->heap[child + 1]) child++;
		if (item > h->heap[child]) break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
	}
	h->heap[parent] = item;
	return item;
}

