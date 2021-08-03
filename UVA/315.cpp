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
int n, dfs_num[110], dfs_low[110], parent[110], dfscounter, root, rootchildren;
bool artica[110];
int ans;
vector<vector<int>> adj;
void artic(int u) {
	dfs_low[u] = dfs_num[u] = dfscounter++;
	for (int j = 0; j < (int) adj[u].size(); j++) {
		if (dfs_num[adj[u][j]] == -1) {
			if (u == root)
				rootchildren++;
			parent[adj[u][j]] = u;
			artic(adj[u][j]);

			if (u != root && dfs_low[adj[u][j]] >= dfs_num[u]) {
				artica[u] = 1;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[adj[u][j]]);
		} else if (parent[u] != adj[u][j]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[adj[u][j]]);
		}
	}
}
int main() {
	while (scanf("%d", &n) && n) {
		string s;
		memset(dfs_low, 0, sizeof dfs_low);
		memset(dfs_num, -1, sizeof dfs_num);
		memset(parent, -1, sizeof parent);
		memset(artica, 0, sizeof artica);
		dfscounter = rootchildren = ans = 0;
		adj.assign(n, vector<int>());
		cin.ignore();
		while (getline(cin, s) && s!="0") {
			stringstream ss(s);
			int m;
			ss >> m;
			int tmp;
			while (ss >> tmp) {
				adj[m - 1].push_back(tmp - 1);
				adj[tmp - 1].push_back(m - 1);
			}
		}

		for (int i = 0; i < n; i++) {
			if (dfs_num[i] == -1) {
				rootchildren = 0;
				root = i;
				artic(i);
				artica[root] = rootchildren > 1;
			}
		}
		for (int i = 0; i < n; i++)
			if (artica[i])
				ans++;
		printf("%d\n", ans);

	}
	return 0;
}
