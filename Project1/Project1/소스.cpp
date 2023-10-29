#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

typedef int element;

element top[5];

int main() {
	int score[5];
	int ball[10];
	int space[10];
	int result[5];
	top[0] = 0; top[1] = 0; top[2] = 0; top[3] = 0; top[4] = 0;
	int givenNumber[15];
	int i = 0, p, q, r, s;
	element pinballNumber[5][10];
	for (i; i < 15; i++) {
		printf("숫자를 입력하십시오");
		scanf("%d", &givenNumber[i]);
		getchar();
	}
	for (i = 14; i >= 0; i--) {
		p = 4;
		if (givenNumber[i] == 0) continue;
		else pinballNumber[p][top[p]++] = givenNumber[i];
		if (p == 0)p = 5;
		else p -= 1;
	}
	for (q = 0; q < 5; q++) {
		printf("점수를 입력하십시오");
		scanf("%d", &score[q]);
		getchar();
	}
	for (r = 0; r < 10; r++)
	{
		printf("공을 넣으십시오");
		scanf("%d %d", &ball[r], &space[r]);
		getchar();
		if (pinballNumber[space[r] - 1][top[space[r] - 1] - 1] == ball[r]) {
			pinballNumber[space[r] - 1][top[space[r] - 1] - 1] = 0;
			top[space[r] - 1] -= 1;
		}
		else {
			pinballNumber[space[r] - 1][top[space[r] - 1]++] = ball[r];
		}
	}
	
	for (s = 0; s < 5; s++) {
		int sum = 0;
		for (int k = 0; k < top[s]; k++) {
			sum += pinballNumber[s][k];
		}
		result[s] = score[s] * sum;
			
	}
	printf("(%d, %d, %d, %d, %d)", result[0], result[1], result[2], result[3], result[4]);
}



