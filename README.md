# Queue
순차 자료구조를 이용한 큐 만들기

## problem
void를 제외한 함수들은 return;을 쓰면 안된다 무언가라도 반환을 해야해

## queueS.h
11행: front 와 rear을 QueueType으로 묶어 관리를 편하게 한다

## queueS.cpp
6행: front와 rear을 -1로 초기값을 두어 Q를 생성한다
30행: Q의 rear 값을 1 증가시킨 다음 해당 칸에 data 값을 넣는다
38행: Q의 front 값을 1 증가시킨 다음 대응하는 값을 출력한다
52행: front까지의 값은 출력이 된 값이므로 front+1 부터 출력한다
