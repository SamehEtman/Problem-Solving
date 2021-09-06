#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int arr[2][n];
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i == 0)
                sum1 += arr[i][j];
        }
    }
    ll ans = intMax;
    for (int i = 0; i < n; i++) {
        sum1 -= arr[0][i];
        ans = min(ans, max(sum1, sum2));
        sum2 += arr[1][i];
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