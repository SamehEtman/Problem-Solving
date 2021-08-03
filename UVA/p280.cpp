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
bool visited[120];
vector <vector<int>> adj;
int v;
void dfs(int c){
	for (int i = 0 ; i < (int)adj[c].size() ; i++){
		if (!visited[adj[c][i]]){
			visited[adj[c][i]] = 1;
			dfs(adj[c][i]);
		}
	}
}
int main() {
	while (scanf("%d" , &v)){
		if (!v) break;
		adj.assign(v , vector<int>());
		int node;
		while(scanf("%d" , &node)){
			if (node == 0) break;
			int temp;
			while (scanf("%d" , &temp)){
				if (temp == 0) break;
				adj[node-1].push_back(temp-1);
			}
		}
		int q;
		scanf("%d" , &q);
		int start;
		while (q--){
			memset(visited,0,sizeof visited);
			vector <int> op;
			scanf("%d" , &start);
			dfs(start-1);
			for (int i = 0 ; i < v ; i++){
				if (visited[i] == 0){
					op.push_back(i+1);
				}
			}
			printf((int)op.size() == 0 ? "0\n" :"%d " , (int) op.size());
			for (int i = 0 ; i < (int) op.size() ;i++){
				printf(i== (int) op.size()-1 ? "%d\n" : "%d " , op[i]);
			}
		}
	}

	return 0;
}
