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
#include <set>
#include <iterator>
using namespace std;
int n, m, finalnode, sum, maxi = 0;
vector<vector<pair<int, int>>> adj;
bool visited[100];
void dfs(int v) {
	if (sum > maxi) {
		maxi = sum;
		finalnode = v;
	}
	if (adj[v].size() == 0)
		return;
	if (!visited[adj[v][0].second]) {
		visited[adj[v][0].second] = 1;
		sum += adj[v][0].first;
		dfs(adj[v][0].second);
	}

}
int main() {
	int tc, counter = 1;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		int val[n];
		sum = maxi = finalnode = 0;
		memset(visited, 0, sizeof visited);
		for (int i = 0; i < n; i++) {
			scanf("%d", &val[i]);
		}
		adj.assign(n, vector<pair<int, int>>());
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(make_pair(val[b], b));
		}
		for (int i = 0; i < n; i++)
			sort(adj[i].rbegin(), adj[i].rend());
		dfs(0);
		printf("Case %d: %d %d\n", counter++, maxi, finalnode);
	}
	return 0;
}
