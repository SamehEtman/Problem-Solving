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
#include <iterator>
using namespace std;
vector<vector<int>> adj;
bool visited[100];
void dfs(int v) {
	for (int i = 0; i < (int) adj[v].size(); i++) {
		if (!visited[adj[v][i]]) {
			visited[adj[v][i]] = 1;
			dfs(adj[v][i]);
		}
	}
}
int main() {
	int tc;
	scanf("%d\n", &tc);
	while (tc--) {
		string s;
		getline(cin,s);
		memset(visited , 0 , sizeof visited);
		adj.assign((int)s[0] - 'A'+1, vector<int>());
		while (getline(cin,s)) {
			if (s.size() == 0)
				break;
			adj[s[0] - 'A'].push_back(s[1] - 'A');
			adj[s[1] - 'A'].push_back(s[0] - 'A');
		}
		int ans = 0;
		for (int i = 0; i < (int)adj.size(); i++) {
			if (!visited[i]) {
				visited[i] = 1;
				ans++;
				dfs(i);
			}
		}
		cout << ans << endl;
		if (tc) cout <<endl;
	}
	return 0;
}
