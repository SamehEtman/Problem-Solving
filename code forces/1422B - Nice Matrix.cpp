#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    ll ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < (m + 1) / 2; j++) {
            vector<int> heads;
            if (n - i - 1 == i) {
                heads.push_back(arr[i][j]);
                heads.push_back(arr[i][m - j - 1]);
            } else if (m - j - 1 == j) {
                heads.push_back(arr[i][j]);
                heads.push_back(arr[n - i - 1][j]);
            } else {
                heads.push_back(arr[i][j]);
                heads.push_back(arr[n - i - 1][j]);
                heads.push_back(arr[i][m - 1 - j]);
                heads.push_back(arr[n - i - 1][m - j - 1]);
            }
            sort(heads.begin(), heads.end());
            int median = heads[1];
            for (int z = 0; z < heads.size(); z++) {
                ans += abs(median - heads[z]);
            }
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