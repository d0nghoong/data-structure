#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct listPointer {
	int number;
	struct listPointer* prev;
	struct listPointer* next;
}listPointer;

typedef struct {
	listPointer* head;
}listHead;

listHead* createlistHead();
void INSERT(listHead* h, int number);
void DELETE(listHead* h, int number);
void print_forward(listPointer* list);
void print_reverse(listPointer* list);

listHead* createlistHead() {
	listHead* h;
	h = (listHead*)malloc(sizeof(listHead));
	h->head = NULL;
	return h;
}

void INSERT(listHead* h, int number) {
	listPointer* newNode;
	listPointer* temp;
	temp = h->head;
	newNode = (listPointer*)malloc(sizeof(listPointer));
	newNode->number = number;
	if (temp == NULL) {
		h->head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		return;

	}
	if (newNode->number < temp->number) {
		newNode->next = temp;
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
		h->head = newNode;
		return;

	}

	while (newNode->number > temp->number) {
		if (temp->next == h->head) break;
		temp = temp->next;

	}
	if (newNode->number == temp->number) {
		printf("중복된 숫자는 입력 불가능 합니다\n");
		return;
	}
	temp->next->prev = newNode;
	newNode->next = temp->next;
	temp->next = newNode;
	newNode->prev = temp;

}



void DELETE(listHead* h, int number) {
	listPointer* temp;
	temp = h->head;
	while (temp->number != number)
	{
		if (temp->next == h->head) {
			printf("숫자가 존재하지 않습니다\n"); return;
		}
		temp = temp->next;
	}
	if (temp == h->head) {
		h->head = temp->next == temp ? NULL : temp->next;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
}

void print_forward(listPointer* list) {
	listPointer* curr;
	FILE* outfile;

	outfile = fopen("./hw2 output.txt", "a");
	if (list) {
		curr = list;
		while (1) {
			fprintf(outfile, "%d", curr->number);
			printf("%d", curr->number);
			curr = curr->next;
			if (curr == list) break;
		}
	}
	fprintf(outfile, "\n");
	printf("\n");
	fclose(outfile);
}

void print_reverse(listPointer* list) {
	listPointer* curr;
	FILE* outfile;
	outfile = fopen("./hw2 output.txt", "a");
	if (list) {
		curr = list->prev;
		while (curr != list) {
			fprintf(outfile, "%d", curr->number);
			printf("%d", curr->number);
			curr = curr->prev;
		}
		fprintf(outfile, "%d", curr->number);
		printf("%d", curr->number);
	}
	fprintf(outfile, "\n");
	printf("\n");
	fclose(outfile);
}

int main(int argc, char*argv[]) {
	listHead* h;
	h = createlistHead();
	if (argc != 2) {
		printf("usage: ./hw2 input_filename");
		return 0;
	}

	FILE* fp_input = fopen(argv[1], "r");
	if (fp_input == NULL) {
		printf("입력 파일이 없습니다\n");
		return 0;
	}
	int value = 0;
	char operation[100] = {};



	while (fscanf(fp_input, "%s", operation) == 1) {
		if (strcmp(operation, "INSERT") == 0 || strcmp(operation, "DELETE") == 0)
		{
			fscanf(fp_input, "%d", &value);
			if (strcmp(operation, "INSERT") == 0) {
				INSERT(h, value);
			}
			else if (strcmp(operation, "DELETE") == 0) {
				DELETE(h, value);
			}
		}
		else if (strcmp(operation, "ASCEND") == 0) {
			print_forward(h->head);
		}
		else if (strcmp(operation, "DESCEND") == 0) {
			print_reverse(h->head);
		}
	}
	fclose(fp_input);
}