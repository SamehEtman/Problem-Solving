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
vector<int> dfs_num, dfs_low, parent;
int dfsDepth, rootChildren, rootNode;

void findAtriculationAndBridge(int u) {
    dfs_num[u] = dfs_low[u] = dfsDepth++;

    for (int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (dfs_num[v] == 0) {
            parent[v] = u;
            if (u == rootNode)
                rootChildren++;
            findAtriculationAndBridge(v);
            if (dfs_low[v] >= dfs_num[u]) {
                // this is articultation point
                cout << u << endl;
            }
            if (dfs_low[v] > dfs_num[u]) {
                // this is a bridge from u -> v
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}
int main() {
    int N = 5;  // number of nodes
    adjList.assign(N, vector<int>());
    dfs_num.assign(N, 0);
    dfs_low.assign(N, 0);
    parent.assign(N , 0);
    fillGraph(N);
    findAtriculationAndBridge(0);
}