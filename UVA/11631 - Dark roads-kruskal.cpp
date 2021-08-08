/*
    the idea is to find the cost of the MST
    then substract it from the total cost
    here we calcualte the mst using kruskal's algorithm

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>

int V, E;
vector<pair<int, pair<int, int>>> edgeList;

class UnionFind
{
private:
    vi rank, p, setSize;
    int numSets;

public:
    UnionFind(int N)
    {
        rank.assign(N, 0);
        p.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
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
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
                setSize[y] += setSize[x];
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main()
{
    while (cin >> V >> E && V && E)
    {
        int total = 0;
        for (int i = 0; i < E; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            total += w;
            edgeList.push_back(make_pair(w, make_pair(x, y)));
        }
        sort(edgeList.begin(), edgeList.end());
        int mstCost = 0;
        UnionFind UF(V);

        for (int i = 0; i < E; i++)
        {
            pair<int, pair<int, int>> front = edgeList[i];

            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                mstCost += front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
        }
        cout << total - mstCost << endl;
    }

    return 0;
}
