
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
vector<vector<pair<int, double>>> adjList;
priority_queue<pair<double, int>> pq;
vector<pair<double, double>> pairs;
vector<bool> visited;
int V;

double calcDist(pair<double, double> p1, pair<double, double> p2)
{
    return sqrt(pow(p1.first - p2.first, 2) +
                pow(p1.second - p2.second, 2));
}

void process(int u)
{
    visited[u] = 1;
    for (int j = 0; j < adjList[u].size(); j++)
    {
        pair<int, double> v = adjList[u][j];
        if (!visited[v.first])
        {
            pq.push(make_pair(-v.second, -v.first));
        }
    }
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> V;
        adjList.assign(V, vector<pair<int, double>>());
        visited.assign(V, 0);
        pairs.clear();
        for (int i = 0; i < V; i++)
        {
            double a, b;
            cin >> a >> b;
            pairs.push_back(make_pair(a, b));
        }
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i == j)
                    continue;
                adjList[i].push_back(make_pair(j, calcDist(pairs[i], pairs[j])));
            }
        }

        // calculate minimum spanning tree (MST) using prim's algorithm
        double mstCost = 0;
        process(0);
        while (!pq.empty())
        {
            double w = -pq.top().first;
            int u = -pq.top().second;
            pq.pop();
            if (!visited[u])
            {
                mstCost += w;
                process(u);
            }
        }
        cout << fixed << setprecision(2) << mstCost << endl;
        if (tc)
            cout << endl;
    }
    return 0;
}
