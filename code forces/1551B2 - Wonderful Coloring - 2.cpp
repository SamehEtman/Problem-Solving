#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, vector<int> > mp;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (mp[arr[i]].size() < k) {
            mp[arr[i]].push_back(i);
        }
    }
    int length = 0;
    for (auto v : mp)
        length += v.second.size();
    length = length - length % k;
    int color = 0;
    vector<int> ans(n, 0);
    for (auto i : mp) {
        bool flag = 0;
        for (auto j : i.second) {
            ans[j] = ++color;
            color %= k;
            length--;
            if (length == 0) {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}