/*
    simply check if it's a bibartite graph or not
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647

int tc, N, E;
vector<vector<int>> adjList;

int main()
{
    while (cin >> N && N)
    {
        int a, b;
        adjList.clear();
        adjList.assign(N + 1, vector<int>());
        while (cin >> a >> b && (a && b))
        {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        queue<int> q;
        q.push(1);
        vector<int> d(N, intMax);
        bool isBibartite = true;
        while (isBibartite && !q.empty())
        {
            int u = q.front();
            q.pop();
            for (int j = 0; j < adjList[u].size(); j++)
            {
                int v = adjList[u][j];
                if (d[v] == intMax)
                {
                    d[v] = 1 - d[u];
                    q.push(v);
                }
                else if (d[v] == d[u])
                {
                    isBibartite = false;
                    break;
                }
            }
        }
        cout << (isBibartite ? "YES\n" : "NO\n");
    }
    return 0;
}