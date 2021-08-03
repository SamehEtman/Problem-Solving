#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <string>
#include <queue>
#include <iterator>
using namespace std;
bool visited1[150], visited2[150];
char op[150][150];
int adj[150][150];
int N;
void dfs(int cur, int des) {
	if (cur == des)
		return;
	visited1[cur] = 1;
	for (int i = 0; i < N; i++) {
		if (adj[cur][i] && !visited1[i]) {
			dfs(i, des);
		}
	}
}
int main() {
	int tc, counter = 1;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &adj[i][j]);
		memset(visited1, 0, sizeof visited1);
		dfs(0, 101);
		for (int j = 0; j < N; j++)
			visited2[j] = visited1[j];
		for (int i = 0; i < N; i++) {
			memset(visited1, 0, sizeof visited1);
			dfs(0, i);
			for (int j = 0; j < N; j++) {
				if (visited2[j] && !visited1[j])
					op[i][j] = 'Y';
				else
					op[i][j] = 'N';
			}
			op[i][i] = visited2[i]? 'Y' :'N';
		}
		printf("Case %d:\n", counter++);
		printf("+");
		for (int j = -N + 1; j < N; j++)
			printf("-");
		puts("+");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("|%c", op[i][j]);
			}
			puts("|");
			putchar('+');
			for (int j = -N + 1; j < N; j++)
				putchar('-');
			puts("+");
		}

	}
	return 0;
}
