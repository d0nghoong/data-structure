#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENT 100

#include<stdio.h>
#include<stdlib.h>

typedef struct heapType {
	int heap[MAX_ELEMENT];
	int heap_size;
}heapType;

heapType* createHeapType();
void insertHeapType(heapType* h, int item);
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
	int temp = h->heap[1];
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
	return temp;
}

void printHeap(heapType* h) {
	int i;
	printf("Heap: ");
	for (i = 1; i <= h->heap_size; i++) {
		printf("[%d]", h->heap[i]);
	}
}

void main() {
	int i, n, item;
	heapType* heap = createHeapType();
	insertHeapType(heap, 10);
	insertHeapType(heap, 45);
	insertHeapType(heap, 19);
	insertHeapType(heap, 11);
	insertHeapType(heap, 96);

	printHeap(heap);
	n = heap->heap_size;
	for (i = 1; i <= n; i++) {
		item = deleteHeapType(heap);
		printf("\n delete:[%d]", item);
	}
}