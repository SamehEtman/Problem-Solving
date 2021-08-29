#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a.push_back('1');
    b.push_back('1');
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[i] == '1') - (a[i] == '0');
        if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && ans != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
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