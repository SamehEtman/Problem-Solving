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
string nts[100001];
vector<vector<int>> adj;
vector<int> s;
int dfs_num[100001], dfs_low[100001], dfscounter, ans, visited[100001];

void scc(int u) {
	dfs_low[u] = dfs_num[u] = ++dfscounter;
	visited[u] = 1;
	s.push_back(u);
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (!dfs_num[v]) {
			scc(v);
		}
		if (visited[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
	if (dfs_low[u] == dfs_num[u]) {
		ans++;
		while (1) {
			int v = s.back();
			s.pop_back();
			visited[v] = 0;
			if (u == v)
				break;
		}
	}
}

void initial() {
	adj.assign(n + 1, vector<int>());
	memset(dfs_num, 0, sizeof dfs_num);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(visited, 0, sizeof visited);
	mp.clear();
	s.clear();
	ans = 0;
	for (int i = 0; i < 100001; i++)
		nts[i].clear();
}
int main() {
	while (scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0)
			break;
		initial();

		cin.ignore();
		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			mp[s] = i + 1;
		}
		for (int i = 0; i < m; i++) {
			string s1, s2;
			getline(cin, s1);
			getline(cin, s2);
			adj[mp[s1]].push_back(mp[s2]);
		}

		for (int i = 1; i <= n; i++)
			if (!dfs_num[i])
				scc(i);
		cout << ans << endl;
	}
	return 0;
}
