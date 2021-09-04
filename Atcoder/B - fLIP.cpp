#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i * (m - j) + j * (n - i) == k) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}