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
vector<int> tp;
int dfs_num[10000], dfs_low[10000], parent[10000], dfscounter, root,
		rootchildren, ans, visited[10001];
bool artica[120];
void artic(int u) {
	dfs_num[u] = dfs_low[u] = dfscounter++;
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (dfs_num[v] == -1) {
			parent[v] = u;
			if (u == root)
				rootchildren++;
			artic(v);

			if (dfs_low[v] >= dfs_num[u])
				artica[u] = 1;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (parent[u] != v) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

void initial() {
	adj.assign(n, vector<int>());
	memset(dfs_num, -1, sizeof dfs_num);
	memset(artica, 0, sizeof artica);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(parent, -1, sizeof parent);
	memset(visited, 0, sizeof visited);
	mp.clear();
	tp.clear();
	ans = 0;

}
int main() {
	int counter = 1;
	while (scanf("%d", &n) && n) {
		if (counter > 1)
			cout << endl;
		initial();

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			mp[s] = i;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			adj[mp[s1]].push_back(mp[s2]);
			adj[mp[s2]].push_back(mp[s1]);
		}

		for (int i = 0; i < n; i++) {
			if (dfs_num[i] == -1) {
				root = i;
				rootchildren = 0;
				artic(i);
				artica[root] = rootchildren > 1;
			}
		}
		for (int i = 0; i < n; i++)
			if (artica[i])
				ans++;
		printf("City map #%d: %d camera(s) found\n", counter++, ans);
		set<string> vs;
		for (int i = 0; i < n; i++)
			if (artica[i])
				for (map<string, int>::iterator it = mp.begin(); it != mp.end();
						it++)
					if (it->second == i)
						vs.insert(it->first);
		for (auto it : vs)
			cout << it << endl;

	}
	return 0;
}
