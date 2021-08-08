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

double calcDist(pair<int, int> p1, pair<int, int> p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main()
{
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n, r;
        cin >> n >> r;
        vector<pair<int, int>> coords; // save input coordinates
        edgeList.clear();
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            coords.push_back(make_pair(x, y));
        }
        // filling edgeList
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                edgeList.push_back(make_pair(calcDist(coords[i], coords[j]), make_pair(i, j)));
            }
        }

        // kruskal's algorithm

        double inStateCost = 0, // road
            outStateCost = 0,   // railroad
            statesNum = 1;

        sort(edgeList.begin(), edgeList.end());
        UnionFind UF(n);
        for (int i = 0; i < edgeList.size(); i++)
        {
            pair<double, pair<int, int>> front = edgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                if (front.first > r)
                {
                    statesNum++;
                    outStateCost += front.first;
                }
                else
                {
                    inStateCost += front.first;
                }
                UF.unionSet(front.second.first, front.second.second);
            }
        }

        cout << "Case #" << t << ": " << statesNum
             << " " << round(inStateCost) << " " << round(outStateCost) << endl;
    }
    return 0;
}
