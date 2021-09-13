#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;
class UnionFind {
   private:
    vector<int> p, rank, setSize;
    int numSets;

   public:
    UnionFind(int N) {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y]) {
                p[y] = x;
                setSize[x] += setSize[y];
            } else {
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

void solve() {
    int n, m, e;
    cin >> n >> m >> e;
    UnionFind UF1(n + 1);
    UnionFind UF2(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        UF1.unionSet(a, b);
    }
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        UF2.unionSet(a, b);
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (UF1.findSet(i) != UF1.findSet(j) &&
                UF2.findSet(i) != UF2.findSet(j)) {
                UF1.unionSet(i, j);
                UF2.unionSet(i, j);
                ans.push_back({i, j});
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
}