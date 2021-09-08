#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans(n, 0);
    for (int i = 1; i < n; i++) {
        ans[i] = (ans[i - 1] ^ arr[i - 1]) & (~arr[i]);
    }
    for (int i = 0; i < n; i++)
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