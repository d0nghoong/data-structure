#include "linkedQueue.h"
int main() {
	LQueueType* LQ = createLinkedQueue();
	element data;
	printf("\n ���� A>>"); enLQueue(LQ, 'A'); print(LQ);
	printf("\n ���� B>>"); enLQueue(LQ, 'B'); print(LQ);
	printf("\n ���� C>>"); enLQueue(LQ, 'C'); print(LQ);
	data = peek(LQ); printf("peek item: %c\n", data);
	printf("\n����>>"); data = deLQueue(LQ); print(LQ);
	printf("\t���� ������:%c", data);
	printf("\n����>>"); data = deLQueue(LQ); print(LQ);
	printf("\t���� ������:%c", data);
	printf("\n����>>"); data = deLQueue(LQ); print(LQ);
	printf("\t���� ������:%c", data);
}