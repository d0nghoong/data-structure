#include"cQueue.h"

void main(void) {
	QueueType* cQ = createCqueue();
	element data;
	printf("\n***** ���� ť ���� *****\n");
	printf("\n���� A>>"); enCqueue(cQ, 'A'); printCq(cQ);
	printf("\n���� B>>"); enCqueue(cQ, 'B'); printCq(cQ);
	printf("\n���� C>>"); enCqueue(cQ, 'C'); printCq(cQ);
	data = peek(cQ); printf("peek item: %c\n", data);
	printf("\n����>>"); data = deCequeue(cQ); printCq(cQ);
	printf("\t���� ������: %c", data);
	printf("\n����>>"); data = deCequeue(cQ); printCq(cQ);
	printf("\t���� ������: %c", data);
	printf("\n����>>"); data = deCequeue(cQ); printCq(cQ);
	printf("\t���� ������: %c", data);
	printf("\n���� D>>"); enCqueue(cQ, 'D'); printCq(cQ);
	printf("\n���� E>>"); enCqueue(cQ, 'E'); printCq(cQ);
}




