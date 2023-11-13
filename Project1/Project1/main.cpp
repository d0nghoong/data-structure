#include"cQueue.h"

void main(void) {
	QueueType* cQ = createCqueue();
	element data;
	printf("\n***** 원형 큐 연산 *****\n");
	printf("\n삽입 A>>"); enCqueue(cQ, 'A'); printCq(cQ);
	printf("\n삽입 B>>"); enCqueue(cQ, 'B'); printCq(cQ);
	printf("\n삽입 C>>"); enCqueue(cQ, 'C'); printCq(cQ);
	data = peek(cQ); printf("peek item: %c\n", data);
	printf("\n삭제>>"); data = deCequeue(cQ); printCq(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n삭제>>"); data = deCequeue(cQ); printCq(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n삭제>>"); data = deCequeue(cQ); printCq(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n삽입 D>>"); enCqueue(cQ, 'D'); printCq(cQ);
	printf("\n삽입 E>>"); enCqueue(cQ, 'E'); printCq(cQ);
}




