#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define MAX_LINE 20

#include<stdio.h>
#include<queue>
#include<iostream>

int visited[MAX_LINE][MAX_LINE];
int distance[MAX_LINE][MAX_LINE];
int maze[MAX_LINE][MAX_LINE] = { 1, };
int x_dir[4] = { 1,-1,0,0 };
int y_dir[4] = { 0,0,1,-1 };


std::pair<int, int>p;
std::queue<std::pair<int, int>> q;

int bfsFunction(int first_x, int first_y, int value) {
	std::pair<int, int>temp;
	int i;
	int bef_x, bef_y, x, y;
	p.first = first_x;
	p.second = first_y;
	visited[first_x][first_y] = TRUE;
	distance[first_x][first_y] = 1;
	p = std::make_pair(first_x, first_y);
	q.push(p);


	while (!q.empty()) {
		bef_x = q.front().first;
		bef_y = q.front().second;

		for (i = 0; i < 4; i++) {
			x = bef_x + x_dir[i];
			y = bef_y + y_dir[i];
			if (x < 0 || x >= MAX_LINE || y < 0 || y >= MAX_LINE) {
				continue;
			}
			else if (visited[x][y] == FALSE && maze[x][y] == 0) {
				q.push(std::make_pair(x, y));
				distance[x][y] = distance[bef_x][bef_y] + 1;
				visited[x][y] = TRUE;
			}
		}
		q.pop();
	}
	return distance[value - 1][value - 1];
}

int main() {
	int i, j, k, temp, result;
	printf("줄의 크기를 입력하시오(20 이하):");
	std::cin >> i;
	std::cin.ignore();

	printf("미로를 입력하시오:\n");
	for (j = 0; j < i; j++) {
		for (k = 0; k < i; k++) {
			std::cin >> temp;
			maze[j][k] = temp;
			std::cin.ignore();
		}
	}
	result = bfsFunction(0, 0, i);

	if (result == 0)std::cout << "길이 없습니다";
	else std::cout << "길이:" << result;

	return 0;
}
