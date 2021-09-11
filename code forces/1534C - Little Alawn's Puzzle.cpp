#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;
vector<vector<int>> adjList;
bool visited[1000000];
void dfs(int u) {
    visited[u] = 1;
    for (int j = 0; j < adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (!visited[v]) {
            dfs(v);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    adjList.assign(n + 1, vector<int>());
    memset(visited, 0, sizeof visited);

    int arr1[n + 1], arr2[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr1[i];
    for (int i = 1; i <= n; i++)
        cin >> arr2[i];

    for (int i = 1; i <= n; i++) {
        adjList[arr1[i]].push_back(arr2[i]);
        adjList[arr2[i]].push_back(arr1[i]);
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            ans = (ans * 2) % mod;
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
}