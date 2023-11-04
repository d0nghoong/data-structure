# include"queueS.h"

int main() {
	QueueType* Q1 = createQueue();
	element data;
	printf("\n***** 순차 큐 연산 *****\n");
	printf("\n삽입 A>>>"); enQueue(Q1, 'A'); print(Q1);
	printf("\n삽입 B>>>"); enQueue(Q1, 'B'); print(Q1);
	printf("\n삽입 C>>>"); enQueue(Q1, 'C'); print(Q1);
	data = peek(Q1); printf("\tpeek item: %c", data);
	printf("\n삭제>>>"); data = deQueue(Q1); print(Q1);  printf("\t삭제데이터:%c", data);
	printf("\n삭제>>>"); data = deQueue(Q1); print(Q1);  printf("\t삭제데이터:%c", data);
	printf("\n삭제>>>"); data = deQueue(Q1); print(Q1);  printf("\t삭제데이터:%c", data);

	printf("\n삽입 D>>>"); enQueue(Q1, 'D'); print(Q1);
	printf("\n삽입 E>>>"); enQueue(Q1, 'E'); print(Q1);

}