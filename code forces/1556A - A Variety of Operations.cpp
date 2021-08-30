#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int b, c;
    cin >> b >> c;
    if (b == c && c != 0) {
        cout << 1 << endl;
        return;
    } else if (b == c && c == 0) {
        cout << 0 << endl;
        return;
    }
    if ((b + c) % 2 == 0)
        cout << 2 << endl;
    else
        cout << -1 << endl;
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