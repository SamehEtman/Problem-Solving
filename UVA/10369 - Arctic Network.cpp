#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
int S, N;

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

vector<pair<double, pair<int, int>>> edgeList;

double calcDist(pair<int, int> p1, pair<int, int> p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
int main()
{
    int TC;
    cin >> TC;
    for (int tc = 0; tc < TC; tc++)
    {

        cin >> S >> N;

        edgeList.clear();

        vector<pair<int, int>> coords;
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            coords.push_back(make_pair(a, b));
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                edgeList.push_back(make_pair(calcDist(coords[i], coords[j]),
                                             make_pair(i, j)));
            }
        }
        // make N-S edges to be the least and these connected forests
        // will connect with the satallites

        sort(edgeList.begin(), edgeList.end());
        int count = 0;
        double d = 0;
        UnionFind UF(N);
        for (int j = 0; j < edgeList.size(); j++)
        {
            pair<double, pair<int, int>> front = edgeList[j];

            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                count++;
                d = front.first, 2;
                UF.unionFind(front.second.first, front.second.second);
            }
            if (count == N - S)
                break;
        }
        cout << fixed << setprecision(2) << d << endl;
    }
    return 0;
}
