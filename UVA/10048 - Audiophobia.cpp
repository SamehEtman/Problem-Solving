#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>

int V, E, Q, ans;
vector<pair<double, pair<int, int>>> edgeList;
vector<vector<pair<int, int>>> adjList;
vector<bool> visited;

class UnionFind
{
private:
    vi p, rank;

public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        rank.assign(N, 0);
        for (int i = 0; i < N; i++)
        {
            p[i] = i;
        }
    }
    int findSet(int i)
    {
        return (p[i] == i ? i : p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
            }
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                {
                    rank[y]++;
                }
            }
        }
    }
};

void calcDist(int u, int d, int maximum)
{
    if (u == d)
    {
        ans = maximum;
        return;
    }
    visited[u] = 1;
    for (int j = 0; j < adjList[u].size(); j++)
    {
        pair<int, int> v = adjList[u][j];
        if (!visited[v.first])
        {
            calcDist(v.first, d, max(maximum, v.second));
        }
    }
}

int main()
{
    int tc = 0;
    while (cin >> V >> E >> Q)
    {
        if (V == 0 && E == 0 && Q == 0)
            break;
        if (tc++)
            cout << endl;

        edgeList.clear();

        for (int i = 0; i < E; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            edgeList.push_back(make_pair(w, make_pair(x, y)));
        }

        double mstCost = 0;
        sort(edgeList.begin(), edgeList.end());

        // kruskal's algorithm for MST ans forming the graph (tree) of the MST in adjList

        UnionFind UF(V + 1);
        adjList.assign(V + 1, vector<pair<int, int>>());

        for (int i = 0; i < edgeList.size(); i++)
        {
            pair<double, pair<int, int>> front = edgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                adjList[front.second.first].push_back(make_pair(front.second.second, front.first));
                adjList[front.second.second].push_back(make_pair(front.second.first, front.first));
                UF.unionSet(front.second.first, front.second.second);
            }
        }

        // calculate max edge in every query
        ans = -1;
        printf("Case #%d\n", tc);
        visited.assign(V + 1, 0);

        for (int i = 0; i < Q; i++)
        {
            int x, y;
            cin >> x >> y;
            calcDist(x, y, ans);

            if (ans > -1)
                cout << ans << endl;
            else
                cout << "no path" << endl;
            ans = -1;
            visited.assign(V + 1, 0);
        }
    }
    return 0;
}
