// O(v+E)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

int n, m, ans;
vector<vector<int>> adjList;
int dfs_low[60] , dfs_num[60] , parent[60] ,depth = 0;


void findBridge(int u)
{
    dfs_num[u] = dfs_low[u] = depth++;

    for (int j = 0; j < adjList[u].size(); j++)
    {
        int v = adjList[u][j];

        if (dfs_num[v] == 0)
        {
            parent[v] = u;
            findBridge(v);
            if (dfs_low[v] > dfs_num[u])
            {
               ans++;
            }
            dfs_low[u] = min(dfs_low[v], dfs_low[u]);
        }
        else if (parent[u] != v)
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}
void solve() {
    cin >> n >> m;

    adjList.assign(n + 1, vector<int>());
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    findBridge(1);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
/*
    O(E(V+E))

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

int n, m, ans;
vector<vector<int>> adjList;
bool visitedEdges[1500][1500];
bool visitedVertix[60];

void dfs(int u) {
    visitedVertix[u] = 1;
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (!visitedEdges[u][v] && !visitedVertix[v]) {
            dfs(v);
        }
    }
}

void check() {
    for (int j = 1; j <= n; j++) {
        if (visitedVertix[j] == 0) {
            ans++;
            return;
        }
    }
}
void init() {
    memset(visitedVertix, 0, sizeof visitedVertix);
    memset(visitedEdges, 0, sizeof visitedEdges);
}
void solve() {
    cin >> n >> m;

    adjList.assign(n + 1, vector<int>());
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (int i = 0; i < m; i++) {
        visitedEdges[edges[i].first][edges[i].second] = 1;
        dfs(edges[i].first);
        check();
        init();
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}*/