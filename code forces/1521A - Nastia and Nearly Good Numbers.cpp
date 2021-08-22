#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int a, b;
    cin >> a >> b;
    if (b == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << a << " " << (ll)a * b << " " << (ll)a * (b + 1) << endl;
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