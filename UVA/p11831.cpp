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
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<int> visited;
vector<vii> adjlist;
int dfs(int u) {
	visited[u] = 1;
	for (int i = 0; i < adjlist[u].size(); i++) {
		if (!visited[adjlist[u][i].first]) {
			dfs(adjlist[u][i].first);
		}
	}
}
int main() {
	int n, m, s;
	while (scanf("%d %d %d", &n, &m, &s) != EOF) {
		if (n == 0 && m == 0 && s == 0)
			break;
		char arr[n][m];
		char c;
		int x, y;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] != '#' && arr[i][j] != '*' && arr[i][j] != '.') {
					c = arr[i][j];
					x = i;
					y = j;
				}
			}
		}
		string ins;
		int direction;
		if (c == 'N')
			direction = 0;
		else if (c == 'L')
			direction = 1;
		else if (c == 'S')
			direction = 2;
		else if (c == 'O')
			direction = 3;
		cin >> ins;
		int ans = 0;
		for (int i = 0; i < (int) ins.size(); i++) {
			if (ins[i] == 'D') {
				direction = (direction + 1) % 4;
			} else if (ins[i] == 'E') {
				if (direction == 0)
					direction = 3;
				else
					direction = (direction - 1) % 4;
			} else if (ins[i] == 'F') {
				if (direction == 0) {
					if (x - 1 < 0 || arr[x - 1][y] == '#') {
						;
					} else {
						x--;
						if (arr[x][y] == '*')
							ans++;
						arr[x][y] = '-';
					}
				} else if (direction == 1) {
					if (y + 1 >= m || arr[x][y + 1] == '#') {
						;
					} else {
						y++;
						if (arr[x][y] == '*')
							ans++;
						arr[x][y] = '-';
					}
				} else if (direction == 2) {
					if (x + 1 >= n || arr[x + 1][y] == '#') {
						;
					} else {
						x++;
						if (arr[x][y] == '*')
							ans++;
						arr[x][y] = '-';
					}
				} else if (direction == 3) {
					if (y - 1 < 0 || arr[x][y - 1] == '#') {
						;
					} else {
						y--;
						if (arr[x][y] == '*')
							ans++;
						arr[x][y] = '-';
					}
				}

			}

		}
		cout << ans << endl;
	}

	return 0;
}
