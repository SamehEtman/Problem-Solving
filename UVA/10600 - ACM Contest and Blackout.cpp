#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>

int V, E;
vector<pair<double, pair<int, int>>> edgeList;
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

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> V >> E;

        edgeList.clear();

        // fill the edge list
        for (int i = 0; i < E; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            edgeList.push_back(make_pair(w, make_pair(x, y)));
        }

        sort(edgeList.begin(), edgeList.end());

        // calculate the best MST ans store the optimal Edges
        vector<pair<int, int>> optimalEdges;

        int mstCostOne = 0;
        UnionFind UF(V + 1);
        for (int i = 0; i < edgeList.size(); i++)
        {
            pair<double, pair<int, int>> front = edgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                mstCostOne += front.first;
                optimalEdges.push_back(make_pair(front.second.first, front.second.second));
                UF.unionSet(front.second.first, front.second.second);
            }
        }
        // flag each of the optimal edges and try find the optimal MST
        // store the minimum MST after flagging each optimal edge

        int mstCostTwo = intMax;
        for (int z = 0; z < optimalEdges.size(); z++)
        {
            int mstCost = 0;
            UnionFind UF(V + 1);
            for (int i = 0; i < edgeList.size(); i++)
            {
                pair<double, pair<int, int>> front = edgeList[i];
                if (front.second.first == optimalEdges[z].first && front.second.second == optimalEdges[z].second)
                {
                    continue;
                }
                if (!UF.isSameSet(front.second.first, front.second.second))
                {
                    mstCost += front.first;
                    UF.unionSet(front.second.first, front.second.second);
                }
            }
            if (mstCost >= mstCostOne)
                mstCostTwo = min(mstCostTwo, mstCost);
        }

        cout << mstCostOne << " " << mstCostTwo << endl;
    }
    return 0;
}
