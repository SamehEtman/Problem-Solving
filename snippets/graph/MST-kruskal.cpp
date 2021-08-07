#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647

int V, E;

vector<vector<pair<int, int>>> adjList;
vector<pair<int, pair<int, int>>> EdgeList;
vector<int> tp;
vector<bool> visited;
priority_queue<pair<int, int>> pq;

class UnionFind
{ // OOP style
private:
    vector<int> p, rank, setSize; // remember: vi is vector<int>
    int numSets;

public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
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
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

void kruskal(int u)
{
    int mstCost = 0;
    sort(EdgeList.begin(), EdgeList.end());
    UnionFind UF(V);
    for (int i = 0; i < E; i++)
    {
        pair <int , pair<int ,int >> front = EdgeList[i];
        if (!UF.isSameSet(front.second.first , front.second.second)){
            mstCost += front.first;
            UF.unionSet(front.second.first , front.second.second);
        }
    }
}
int main()
{

    return 0;
}