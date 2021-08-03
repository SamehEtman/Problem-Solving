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
set<pair<int, int>> st;
void artic(int u) {
	dfs_num[u] = dfs_low[u] = dfscounter++;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (dfs_num[v] == -1) {
			parent[v] = u;
			if (u == root)
				rootchildren++;
			artic(v);
			if (dfs_low[v] > dfs_num[u]) {
				st.insert(make_pair(min(u,v), max(u,v)));
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (parent[u] != v) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}
int main() {
	while (scanf("%d", &n) != EOF) {
		memset(dfs_low, 0, sizeof dfs_low);
		memset(dfs_num, -1, sizeof dfs_num);
		memset(parent, -1, sizeof parent);
		memset(artica, 0, sizeof artica);
		dfscounter = rootchildren = ans = 0;
		adj.assign(n, vector<int>());
		st.clear();
		for (int i = 0; i < n; i++) {
			int m , z;
			scanf("%d", &m);
			scanf(" (%d)" , &z);
			for (int j = 0; j < z; j++) {
				int tmp;
				scanf("%d", &tmp);
				adj[m].push_back(tmp);
			}
		}

		for (int i = 0; i < n; i++) {
			if (dfs_num[i] == -1) {
				root = i;
				rootchildren = 0;
				artic(i);
				artica[root] = (rootchildren > 1);
			}
		}
		printf("%d critical links\n" , (int)st.size());
		for (auto it : st){
			printf("%d - %d\n" , it.first , it.second);
		}
		puts("");
	}
	return 0;
}
