#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647

int V, E, dfsCounter, SCCNum;
unordered_map<string, int> mpr;
unordered_map<int, string> mp;
vector<vector<int>> adjList;
vector<int> dfs_num, dfs_low, S;
vector<bool> visited;
void SCC(int u)
{
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    visited[u] = 1;
    S.push_back(u);
    for (int j = 0; j < adjList[u].size(); j++)
    {
        int v = adjList[u][j];
        if (dfs_num[v] == -1)
        {
            SCC(v);
        }
        if (visited[v])
        {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_low[u] == dfs_num[u])
    {
        while (1)
        {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            if (u != v)
            {
                cout << mp[v] << ", ";
            }
            else
            {
                cout << mp[v] << endl;
                break;
            }
        }
    }
}

int main()
{
    int tc = 0;
    while (cin >> V >> E && (V && E))
    {
        if (tc)
            cout << endl;
        adjList.assign(V, vector<int>());
        visited.assign(V, 0);
        dfs_num.assign(V, -1);
        dfs_low.assign(V, -1);
        mp.clear();
        mpr.clear();
        S.clear();
        dfsCounter = SCCNum = 0;
        int idx = 0;
        for (int i = 0; i < E; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if (mpr.find(s1) == mpr.end())
                mpr[s1] = idx++;
            if (mpr.find(s2) == mpr.end())
                mpr[s2] = idx++;

            adjList[mpr[s1]].push_back(mpr[s2]);
        }
        for (auto i : mpr)
        {
            mp[i.second] = i.first;
        }
        printf("Calling circles for data set %d:\n", ++tc);
        for (int i = 0; i < V; i++)
        {
            if (dfs_num[i] == -1)
            {
                SCC(i);
            }
        }
    }
    return 0;
}