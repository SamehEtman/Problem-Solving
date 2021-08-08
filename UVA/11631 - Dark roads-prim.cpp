/*
    the idea is to find the cost of the MST
    then substract it from the total cost
    here we calcualte the mst using prim's algorithm

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647

int V, E;
vector<vector<pair<int, int>>> adjList;
priority_queue<pair<int, int>> pq;
vector<bool> visited;
void process(int u)
{
    visited[u] = 1;
    for (int j = 0; j < adjList[u].size(); j++)
    {
        pair<int, int> v = adjList[u][j];
        if (!visited[v.first])
        {
            pq.push(make_pair(-v.second, -v.first));
        }
    }
}

int main()
{
    while (cin >> V >> E && V && E)
    {
        int x, y, w, total = 0;
        adjList.assign(V, vector<pair<int, int>>());
        visited.assign(V, 0);
        for (int i = 0; i < E; i++)
        {
            cin >> x >> y >> w;
            total += w;
            adjList[x].push_back(make_pair(y, w));
            adjList[y].push_back(make_pair(x, w));
        }

        process(0);
        int mstCost = 0;
        while (!pq.empty())
        {
            int u = -pq.top().second;
            int w = -pq.top().first;
            pq.pop();
            if (!visited[u])
            {
                mstCost += w;
                process(u);
            }
        }
        cout << total - mstCost << endl;
    }

    return 0;
}
