#include "linkedQueue.h"
int main() {
	LQueueType* LQ = createLinkedQueue();
	element data;
	printf("\n 삽입 A>>"); enLQueue(LQ, 'A'); print(LQ);
	printf("\n 삽입 B>>"); enLQueue(LQ, 'B'); print(LQ);
	printf("\n 삽입 C>>"); enLQueue(LQ, 'C'); print(LQ);
	data = peek(LQ); printf("peek item: %c\n", data);
	printf("\n삭제>>"); data = deLQueue(LQ); print(LQ);
	printf("\t삭제 데이터:%c", data);
	printf("\n삭제>>"); data = deLQueue(LQ); print(LQ);
	printf("\t삭제 데이터:%c", data);
	printf("\n삭제>>"); data = deLQueue(LQ); print(LQ);
	printf("\t삭제 데이터:%c", data);
}