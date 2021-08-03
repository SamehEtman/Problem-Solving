#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
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
#include <queue>
#include <set>
#include <map>
#include <iterator>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> tp;
int visited[120];
void dfs(int u) {
	visited[u] = 1;
	for (int i = 0; i < (int) adj[u].size(); i++) {
		if (!visited[adj[u][i]]) {
			dfs(adj[u][i]);
		}
	}
	tp.push_back(u);
}
int main() {
	while (scanf("%d %d", &n, &m)) {
		if (m == 0 && n == 0)
			break;
		adj.assign(n, vector<int>());
		memset(visited, 0, sizeof visited);
		tp.clear();
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a - 1].push_back(b - 1);
		}

		for (int i = 0; i < n; i++)
			if (!visited[i]){
				dfs(i);
			}
		for (int i = tp.size() - 1; i >= 0; i--) {
			printf(i == 0 ? "%d\n" : "%d ", tp[i] + 1);
		}
	}
	return 0;
}

