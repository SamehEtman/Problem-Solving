#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int n = 2 * abs(a - b);
    if (c > n || a > n || b > n) {
        cout << -1 << endl;
        return;
    }
    int d1 = c + n / 2;
    int d2 = c - n / 2;
    if (d1 > 0 && d1 <= n)
        cout << d1 << endl;
    else
        cout << d2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}