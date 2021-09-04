#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n;
    cin >> n;
    int x = 1;
    while (x * (x + 1) < 2 * n) {
        x++;
    }
    vector<int> ans;
    while (n > 0) {
        if (n <= x) {
            ans.push_back(n);
            break;
        } else
            ans.push_back(x);
        n -= x;
        x--;
    }
    for (int i = (int)ans.size() - 1; i >= 0; i--)
        cout << ans[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}