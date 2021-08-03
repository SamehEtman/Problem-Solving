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
string nts[10000];
vector<vector<int>> adj;
vector<int> tp;
int dfs_num[10000], dfs_low[10000], dfscounter, ans, visited[10001];

/*void scc(int u) {
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
}*/
void dfs(int u){
	visited[u] = 1;
	for (int i = 0 ; i <(int) adj[u].size()  ; i++){
		int v = adj[u][i];
		if (!visited[v])
			dfs(v);
	}
	tp.push_back(u);
}

void initial() {
	adj.assign(n+1, vector<int>());
	memset(dfs_num, 0, sizeof dfs_num);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(visited, 0, sizeof visited);
	mp.clear();
	tp.clear();
	ans = 0;
	/*for (int i = 0; i < 120; i++)
		nts[i].clear();*/
}
int main() {
	int tc , counter = 1;
	scanf("%d" , &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);

		initial();

		for (int i = 0 ; i < m ; i++){
			int a , b;
			scanf("%d %d" , &a , &b);
			adj[a].push_back(b);
		}

		for (int i = 1 ; i <= n ; i++)
			if (!visited[i])
				dfs(i);

		reverse(tp.begin() , tp.end());
		memset(visited, 0, sizeof visited);


		for (int i = 0; i < n; i++){
			int u = tp[i];
			if (!visited[u]){
				dfs(u);
				ans++;
			}
		}

		printf("Case %d: %d\n" , counter++ , ans);
	}
	return 0;
}
