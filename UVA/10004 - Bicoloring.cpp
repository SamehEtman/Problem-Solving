#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxInt 2147483647

int tc, N, E;
vector<vector<int>> adjList;

int main()
{
    while (cin >> N >> E && N)
    {
        adjList.clear();
        adjList.assign(N, vector<int>());
        for (int i = 0; i < E; i++)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        queue<int> q;
        vector<int> d(N, maxInt);
        q.push(0);
        d[0] = 0;
        bool isBibtrate = true, flag = false;
        while (!q.empty() && isBibtrate)
        {
            int u = q.front();
            q.pop();
            for (int j = 0; j < adjList[u].size(); j++)
            {
                if (d[adjList[u][j]] == maxInt)
                {
                    d[adjList[u][j]] = 1 - d[u];
                    q.push(adjList[u][j]);
                }
                else if (d[adjList[u][j]] == d[u])
                {
                    isBibtrate = false;
                    break;
                }
            }
        }

        cout << (isBibtrate ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
    }

    return 0;
}