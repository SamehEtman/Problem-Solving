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

vector<pair<int, pair<int, int>>> edgeList;
int main()
{
    int TC;
    cin >> TC;

    for (int tc = 0; tc < TC; tc++)
    {
        if (tc)
            cout << endl;
        cin >> N >> E;

        unordered_map<string, int> cityToNum;
        unordered_map<int, string> numToCity; // useless anyway

        edgeList.clear();
        int idx = 0;
        // map cities to numbers 
        for (int i = 0; i < E; i++)
        {
            string s1, s2;
            int w;
            cin >> s1 >> s2 >> w;
            if (cityToNum.find(s1) == cityToNum.end())
            {
                numToCity[idx] = s1;
                cityToNum[s1] = idx++;
            }
            if (cityToNum.find(s2) == cityToNum.end())
            {
                numToCity[idx] = s2;
                cityToNum[s2] = idx++;
            }
            edgeList.push_back(make_pair(w, make_pair(cityToNum[s1], cityToNum[s2])));
        }

        // calculate MST using kruskal

        sort(edgeList.begin(), edgeList.end());
        int mstCost = 0;
        UnionFind UF(N);
        for (int j = 0; j < edgeList.size(); j++)
        {
            pair<int, pair<int, int>> front = edgeList[j];

            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                mstCost += front.first;
                UF.unionFind(front.second.first, front.second.second);
            }
        }
        cout << mstCost << endl;
    }
    return 0;
}
