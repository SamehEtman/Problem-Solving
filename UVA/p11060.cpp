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
int visited[120] , in[120];
void dfs(int u) {
	visited[u] = 1;
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (!visited[v]) {
			dfs(v);
		}
	}
	tp.push_back(u);
}
int main() {
	int counter = 1;
	while (scanf("%d", &n) != EOF) {
		adj.assign(n, vector<int>());
		memset(visited , 0 , sizeof visited);
		map<int, string> mp;
		tp.clear();
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			mp[i] = s;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			string a, b;
			int c, d;
			cin >> a >> b;
			for (map<int, string>::iterator it = mp.begin(); it != mp.end();
					it++) {
				if (it->second == a)
					c = it->first;
				if (it->second == b)
					d = it->first;
			}
			adj[c].push_back(d);
			in[d]++;
		}
        priority_queue<int, vector<int>, greater<int> > q;
		printf("Case #%d: Dilbert should drink beverages in this order:",
						counter++);
		for (int i = 0 ; i < n ; i++)
			if (in[i] == 0)
				q.push(i);
		while (!q.empty()){
			int t = q.top();
			q.pop();
			for (int i = 0 ; i <adj[t].size();i++){
				in[adj[t][i]]--;
				if (in[adj[t][i]] == 0)
					q.push(adj[t][i]);
			}
			cout << " " << mp[t];
		}
		cout <<".\n\n";
	}
	return 0;
}



/* wrong answer
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
int visited[120] , in[120];
void dfs(int u) {
	visited[u] = 1;
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i];
		if (!visited[v]) {
			dfs(v);
		}
	}
	tp.push_back(u);
}
int main() {
	int counter = 1;
	while (scanf("%d", &n) != EOF) {
		adj.assign(n, vector<int>());
		memset(visited , 0 , sizeof visited);
		map<int, string> mp;
		tp.clear();
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			mp[i] = s;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			string a, b;
			int c, d;
			cin >> a >> b;
			for (map<int, string>::iterator it = mp.begin(); it != mp.end();
					it++) {
				if (it->second == a)
					c = it->first;
				if (it->second == b)
					d = it->first;
			}
			adj[d].push_back(c);
			in[c]++;
		}
		for (int i = 0; i < n; i++) {
					for (int i = 0; i < n; i++) {
						if (!visited[i] && in[i] == 0) {
							dfs(i);
							break;
						}
					}
				}
		printf("Case #%d: Dilbert should drink beverages in this order:",
				counter++);
		for (int i = 0; i < (int)tp.size(); i++) {
			if (i == (int)tp.size()-1) cout << " " << mp[tp[i]] << ".\n\n";
			else cout <<" " << mp[tp[i]];
		}

	}
	return 0;
}
 
 
 */