#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mp;
    cin >> arr[0];
    int edge1, edge2;
    edge1 = arr[0];
    mp[arr[0]]++;
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        if (arr[i] != arr[i - 1])
            mp[arr[i]]++;
    }
    edge2 = arr[n - 1];
    int ans = intMax;
    for (auto x : mp) {
        int temp = 0;
        if (x.first == edge1) {
            temp--;
        }
        if (x.first == edge2)
            temp--;
        temp += x.second + 1;
        ans = min(ans, temp);
    }
    cout << ans << endl;
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