# include"queueS.h"

int main() {
	QueueType* Q1 = createQueue();
	element data;
	printf("\n***** ���� ť ���� *****\n");
	printf("\n���� A>>>"); enQueue(Q1, 'A'); print(Q1);
	printf("\n���� B>>>"); enQueue(Q1, 'B'); print(Q1);
	printf("\n���� C>>>"); enQueue(Q1, 'C'); print(Q1);
	data = peek(Q1); printf("\tpeek item: %c", data);
	printf("\n����>>>"); data = deQueue(Q1); print(Q1);  printf("\t����������:%c", data);
	printf("\n����>>>"); data = deQueue(Q1); print(Q1);  printf("\t����������:%c", data);
	printf("\n����>>>"); data = deQueue(Q1); print(Q1);  printf("\t����������:%c", data);

	printf("\n���� D>>>"); enQueue(Q1, 'D'); print(Q1);
	printf("\n���� E>>>"); enQueue(Q1, 'E'); print(Q1);

}