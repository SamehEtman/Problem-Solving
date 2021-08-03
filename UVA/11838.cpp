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
vector<int> v;
int dfs_num[2100], dfs_low[2100], visited[2100], dfscounter = 0, ans;
void ssc(int u) {
	dfs_low[u] = dfs_num[u] = ++dfscounter;
	visited[u] = 1;
	v.push_back(u);
	for (int i = (int) adj[u].size() -1; i >=0; i--) {
		if (dfs_num[adj[u][i]] == -1) {
			ssc(adj[u][i]);
		}
		if (visited[adj[u][i]]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[adj[u][i]]);
		}
	}
	if (dfs_low[u] == dfs_num[u]) {
		ans++;
		while (1) {
			int t = v.back();
			v.pop_back();
			visited[t] = 0;
			if (u == t)
				break;
		}
	}

}
int main() {
	while (scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0)
			break;
		adj.assign(n+1, vector<int>());
		dfscounter = ans = 0;
		memset(dfs_low, 0, sizeof dfs_low);
		memset(dfs_num, -1, sizeof dfs_num);
		memset(visited, 0, sizeof visited);
		v.clear();
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(b);
			if (c == 2)
				adj[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (dfs_num[i] == -1 && ans <= 1) {
				ssc(i);
			}
		}
		if (ans == 1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
