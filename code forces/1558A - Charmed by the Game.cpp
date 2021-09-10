#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    int alice = (a + b + 1) / 2;
    int broyce = (a + b) / 2;

    set<int> ans;
    for (int i = 0; i <= alice; i++) {
        int y = a - (alice - i);
        if (y >= 0 && y <= broyce) {
            ans.insert(y + i);
        }
    }

    alice = (a + b) / 2;
    broyce = (a + b + 1) / 2;
    for (int i = 0; i <= broyce; i++) {
        int y = b - (broyce - i);
        if (y >= 0 && y <= alice)
            ans.insert(y + i);
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
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