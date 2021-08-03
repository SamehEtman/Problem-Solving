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
map<string, int> mp;
vector<vector<int>> adj;
vector<vector<int>> tmp;
vector<pair<int, int>> tp;
int dfs_num[10000], dfs_low[10000], parent[10000], dfscounter, root,
		rootchildren, ans, visited[10001];
int artica[10000];

void artic(int u) {
	dfs_num[u] = dfs_low[u] = ++dfscounter;

	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (dfs_num[v] == 0) {
			parent[v] = u;
			if (u == root)
				rootchildren++;

			artic(v);

			if (dfs_low[v] >= dfs_num[u])
				artica[u]++;

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

void initial() {
	adj.assign(n, vector<int>());
	memset(dfs_num, 0, sizeof dfs_num);
	memset(artica, 0, sizeof artica);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(parent, -1, sizeof parent);
	memset(visited, 0, sizeof visited);
	mp.clear();
	tp.clear();
	ans = 0;

}
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second > b.second)
		return a.second > b.second;
	else if (a.second == b.second)
		return a.first < b.first;
	return 0;
}

int main() {
	while (scanf("%d %d", &n, &m)) {
		if (m == 0 && n == 0)
			break;
		initial();

		for (int i = 0;; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (a == -1 && b == -1)
				break;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int cc = 0;
		for (int i = 0; i < n; i++) {
			if (!dfs_num[i]) {
				dfscounter = 0;
				cc++;
				root = i;
				rootchildren = 0;
				artic(i);
				artica[i] = rootchildren -1;
			}
		}
		for (int i = 0; i < n; i++) {
			tp.push_back(make_pair(i, artica[i] + cc));
		}
		sort(tp.begin(), tp.end(), cmp);
		for (int i = 0; i < m; i++) {
			cout << tp[i].first << " " << tp[i].second << endl;
		}

		cout << endl;

	}
	return 0;
}
