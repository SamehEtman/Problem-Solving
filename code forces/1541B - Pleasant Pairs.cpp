#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n;
    cin >> n;
    vector<int> v(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        v[temp] = i;
    }
    int ans = 0;
    for (int i = 1; i * (i + 1) <= 2 * n; i++) {
        for (int j = i + 1; j * i <= 2 * n; j++) {
            if (v[i] && v[j] && v[i] + v[j] == i * j) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}