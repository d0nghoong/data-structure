#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

typedef int element;

element top[5];

int main() {
	int score[5] = { 0 };
	int ball[10] = { 0 };
	int space[10] = { 0 };
	int result[5] = { 0 };
	int givenNumber[15] = { 0 };
	int i, p = 4, r, s, q;
	element pinballNumber[5][10];

	top[0] = 0; top[1] = 0; top[2] = 0; top[3] = 0; top[4] = 0;

	for (i = 0; i < 15; i++) {
		printf("���ڸ� �Է��Ͻʽÿ�");
		scanf("%d", &givenNumber[i]);
		getchar();
	}

	for (i = 14; i >= 0; i--) {
		if (givenNumber[i] == 0)
		{
			if (p == 0)p = 4;
			else p -= 1;
			continue;
		}
		else {
			if (p >= 0 && p < 5) {
				if (top[p] == 10) {
					printf("������ �� á���ϴ�"); continue;
				}
				pinballNumber[p][top[p]++] = givenNumber[i];
				printf("%dĭ�� %d\n", p, givenNumber[i]);
				if (p == 0)p = 4;
				else p -= 1;

			}
		}
	}

	for (q = 0; q < 5; q++) {
		printf("������ �Է��Ͻʽÿ�");
		scanf("%d", &score[q]);
		getchar();
	}

	for (r = 0; r < 10; r++)
	{
		printf("���� �����ʽÿ�");
		scanf("%d %d", &ball[r], &space[r]);
		getchar();
		if (pinballNumber[space[r] - 1][top[space[r] - 1] - 1] == ball[r]) {
			pinballNumber[space[r] - 1][top[space[r] - 1] - 1] = 0;
			top[space[r] - 1] -= 1;
			printf("%d ����", ball[r]);
		}
		else {
			if ((top[space[r] - 1]) == 10) { printf("�迭�� �� á���ϴ�"); continue; }
			pinballNumber[space[r] - 1][top[space[r] - 1]++] = ball[r];
			printf("%d�� %d �߰�", space[r] - 1, ball[r]);
		}
	}

	for (s = 0; s < 5; s++) {
		int sum = 0;
		for (int k = 0; k < top[s]; k++)
			sum += pinballNumber[s][k];

		result[s] = score[s] * sum;



	}

	printf("(%d, %d, %d, %d, %d)", result[0], result[1], result[2], result[3], result[4]);
}
