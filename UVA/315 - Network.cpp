/*
    simply check if it's a bibartite graph or not
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647

int tc, N, E, n, dfsCounter, dfsRoot, rootChildren, ans;
vector<vector<int>> adjList;
vector<int> dfs_num, dfs_low, parent;
vector<bool> articulationPoint;

void findArticulationPoint(int u)
{
    dfs_num[u] = dfs_low[u] = ++dfsCounter;

    for (int j = 0; j < adjList[u].size(); j++)
    {
        int v = adjList[u][j];
        if (dfs_num[v] == 0)
        {
            parent[v] = u;
            if (u == dfsRoot)
                rootChildren++;
            findArticulationPoint(v);

            if (dfs_low[v] >= dfs_num[u])
            {
                articulationPoint[u] = 1;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (parent[u] != v)
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main()
{
    while (cin >> N && N)
    {
        adjList.clear();
        dfs_num.clear();
        dfs_low.clear();
        parent.clear();

        adjList.assign(N + 1, vector<int>());
        dfs_num.assign(N + 1, 0);
        dfs_low.assign(N + 1, 0);
        parent.assign(N + 1, 0);
        articulationPoint.assign(N + 1, 0);
        dfsCounter = dfsRoot = rootChildren = ans = 0;

        cin.ignore();
        string s;
        while (getline(cin, s) && s != "0")
        {
            stringstream ss(s);
            ss >> n;
            int a;
            while (ss >> a)
            {
                adjList[n].push_back(a);
                adjList[a].push_back(n);
            }
        }

        for (int i = 1; i <= N; i++)
        {
            if (dfs_num[i] == 0)
            {
                dfsRoot = i;
                rootChildren = 0;
                findArticulationPoint(i);
                articulationPoint[i] = rootChildren > 1;
            }
        }

        for (int i = 1; i <= N; i++)
            if (articulationPoint[i])
                ans++;

        cout << ans << endl;
    }
    return 0;
}