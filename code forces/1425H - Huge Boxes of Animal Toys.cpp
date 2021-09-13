#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<string> ans(4, "Tidak");
    if (a == 0 && d == 0) {
        if (b % 2)
            ans[1] = "Ya";
        else
            ans[2] = "Ya";
    } else if (b == 0 && c == 0) {
        if (a % 2)
            ans[0] = "Ya";
        else
            ans[3] = "Ya";
    } else {
        if ((a + b) % 2)
            ans[0] = ans[1] = "Ya";
        else
            ans[2] = ans[3] = "Ya";
    }
    for (int i = 0; i < 4; i++)
        cout << ans[i] << " ";
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