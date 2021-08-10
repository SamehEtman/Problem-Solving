#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
int N, E;

class UnionFind
{
private:
    vi p, rank;

public:
    UnionFind(int N)
    {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i ? i : p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionFind(int i, int j)
    {
        int x = findSet(i);
        int y = findSet(j);
        if (!isSameSet(x, y))
        {
            if (rank[x] > rank[y])
                p[y] = x;
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

double calcDist(pair<int, int> p1, pair<int, int> p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
vector<pair<double, pair<int, int>>> edgeList;
int main()
{
    int TC;
    cin >> TC;

    for (int tc = 0; tc < TC; tc++)
    {
        if (tc)
            cout << endl;
        cin >> N;
        vector<pair<int, int>> coords(1, pair<int, int>());
        // make an edgelist in which every town is connected to all other towns

        edgeList.clear();
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            coords.push_back(make_pair(a, b));
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                edgeList.push_back(make_pair(calcDist(coords[i], coords[j]), make_pair(i, j)));
            }
        }

        // adding the pre built highways
        cin >> E;
        UnionFind UF(N + 1);
        for (int i = 0; i < E; i++)
        {
            int a, b;
            cin >> a >> b;
            if (!UF.isSameSet(a, b))
            {
                UF.unionFind(a, b);
            }
        }

        // here we find the MST using kruskal
        sort(edgeList.begin(), edgeList.end());
        vector<pair<int, int>> newHighways;
        for (int i = 0; i < edgeList.size(); i++)
        {
            pair<double, pair<int, int>> front = edgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                UF.unionFind(front.second.first, front.second.second);
                newHighways.push_back(make_pair(front.second.first, front.second.second));
            }
        }
        if (newHighways.empty())
        {
            cout << "No new highways need" << endl;
        }
        else
        {
            for (int i = 0; i < newHighways.size(); i++)
            {
                cout << newHighways[i].first << " " << newHighways[i].second << endl;
            }
        }
    }
    return 0;
}
