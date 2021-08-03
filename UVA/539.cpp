// we should remark the visited edges as not visited 
// to keep track of all the possible paths 
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
#include <iterator>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
bool visited [30][30];
vector <vector<int>> adj;

int backtrack(int u) {
	int maxi = 0;
	for (int i = 0 ; i < (int)adj[u].size() ; i++){
		if (!visited[u][adj[u][i]]){
			visited[u][adj[u][i]] = visited[adj[u][i]][u] = 1;
			maxi = max(maxi , 1 + backtrack(adj[u][i]));
			visited[u][adj[u][i]] = visited[adj[u][i]][u] = 0;
		}
	}
	return maxi;
}
int main() {
	int n , m;
	while (scanf("%d %d" , &n , &m) ){
		if (n == 0 && m == 0) break;
		adj.assign(30,vector<int>());
		for (int i = 0 ; i < m ; i++){
			int a , b;
			scanf("%d %d" , &a ,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ans = 0;
		for (int i = 0 ; i < n ; i++){
			memset(visited , 0 , sizeof visited);
			ans = max (ans , backtrack(i));
		}
		printf("%d\n" , ans);
	}

	return 0;
}
