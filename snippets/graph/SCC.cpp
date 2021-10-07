#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
vector<vector<int>> adjList;
vector<bool> visited;

void fillGraph(int N) {
    adjList[0].push_back(2);
    adjList[2].push_back(0);
    adjList[1].push_back(2);
    adjList[2].push_back(1);
    adjList[3].push_back(2);
    adjList[3].push_back(3);
    adjList[0].push_back(4);
    adjList[4].push_back(0);
}
vector<int> dfs_num, dfs_low, parent, s;
int dfsDepth, rootChildren, rootNode, numSCC;

void tarjanSCC(int u) {
    dfs_num[u] = dfs_low[u] = dfsDepth++;
    s.push_back(u);
    visited[u] = 1;
    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[u] == -1)
            tarjanSCC(v);
        if (visited[v])
            // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) {
        // if this is a root (start) of an SCC
        printf("SCC %d:", ++numSCC);
        // this part is done after recursion
        while (1) {
            int v = s.back();
            s.pop_back();
            visited[v] = 0;
            printf(" %d", v);
            if (u == v)
                break;
        }
        printf("\n");
    }
}
int main() {
    int N = 5;  // number of nodes
    adjList.assign(N, vector<int>());
    dfs_num.assign(N, -1);
    dfs_low.assign(N, -1);
    parent.assign(N, 0);
    s.assign(N, 0);
    visited.assign(N, 0);
    fillGraph(N);
    for (int i = 0; i < N; i++)
        if (dfs_num[i]== -1)
            tarjanSCC(i);
}