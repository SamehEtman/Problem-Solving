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
bool visited[120][120];
int ans[100][100], grid[100][100];
int all[2] = { 1, -1 };
vector<vector<int>> adj;
int N, M, r, c;
void dfs(int a, int b) {
    int m,n;

	if (visited[a][b])
		return;
	visited[a][b] = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			 m = a + all[i] * M;
			 n = b + all[j] * N;
			if (m < r && m >= 0 && n < c && n >= 0 && grid[m][n] != -1) {
				ans[m][n]++;
				dfs(m, n);
			}
			m = a + all[i] * N;
			n = b + all[j] * M;
			if (m < r && m >= 0 && n < c && n >= 0 && grid[m][n] != -1) {
				ans[m][n]++;
				dfs(m, n);
			}
		}
	}
}

int main() {
	int tc;
	int counter = 1;
	scanf("%d", &tc);
	while (tc--) {
		memset(visited, 0, sizeof visited);
		memset(ans, 0, sizeof ans);
		memset(grid, 1, sizeof grid);
		scanf("%d %d %d %d", &r, &c, &M, &N);
		int q;
		scanf("%d", &q);
		while (q--) {
			int a, b;
			scanf("%d %d", &a, &b);
			grid[a][b] = -1;
		}
		dfs(0, 0);
		int even = 0, odd = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (M == 0 || N == 0 || M == N)
					ans[i][j] /= 2;
				if (ans[i][j] || (!i && !j)) {
					if (ans[i][j] % 2 == 0)
						even++;
					else
						odd++;
				}
			}
		}
		printf("Case %d: %d %d\n", counter++, even, odd);
	}
	return 0;
}
