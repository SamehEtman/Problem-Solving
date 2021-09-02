#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int x;
    cin >> x;
    int steps = 0;
    while (steps * (steps + 1) < 2 * x)
        steps++;

    if (steps * (steps + 1) / 2 == 1 + x)
        steps++;

    cout << steps << endl;
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