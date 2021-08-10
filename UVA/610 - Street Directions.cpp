#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>

int N, E, dfsCounter, dfsRoot, rootChildern;
vector<vector<int>> adjList;
vector<int> dfs_num, dfs_low, parent;
set<pair<int, int>> edges;
vector<vector<bool>> isBridge;

void findBridge(int u)
{
    dfs_num[u] = dfs_low[u] = dfsCounter++;

    for (int j = 0; j < adjList[u].size(); j++)
    {
        int v = adjList[u][j];

        if (dfs_num[v] == 0)
        {
            if (u == dfsRoot)
                rootChildern++;
            parent[v] = u;
            findBridge(v);
            if (dfs_low[v] > dfs_num[u])
            {
                isBridge[u][v] = 1;
                isBridge[v][u] = 1;
                edges.insert(make_pair(u, v));
                edges.insert(make_pair(v, u));
            }
            dfs_low[u] = min(dfs_low[v], dfs_low[u]);
        }
        else if (parent[u] != v)
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

vector<bool> visited;
void findRoute(int u)
{
    visited[u] = 1;
    for (int j = 0; j < adjList[u].size(); j++)
    {
        int v = adjList[u][j];
        if (!isBridge[u][v])
        {
            isBridge[u][v] = 1;
            isBridge[v][u] = 1;
            edges.insert(make_pair(u, v));
        }
        if (!visited[v])
            findRoute(v);
    }
}
void reset()
{
    isBridge.assign(N + 1, vector<bool>(N + 1, 0));
    adjList.assign(N + 1, vector<int>());
    dfs_low.assign(N + 1, 0);
    dfs_num.assign(N + 1, 0);
    parent.assign(N + 1, 0);
    visited.assign(N + 1, 0);
    edges.clear();

    dfsCounter = dfsCounter = dfsRoot = rootChildern = 0;
}
int main()
{
    int first = 1;
    while (cin >> N >> E)
    {
        if (N == 0 && E == 0)
            break;

        cout << first++ << endl
             << endl;

        reset();

        for (int i = 0; i < E; i++)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        findBridge(1);

        findRoute(1);

        for (auto i : edges)
            cout << i.first << " " << i.second << endl;
        cout << "#\n";
    }
    return 0;
}
