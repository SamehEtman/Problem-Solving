/*
ID: your_id_here
PROG: gift1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> odd, even;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (i % 2 == 0)
            even[temp]++;
        else
            odd[temp]++;
    }
    vector<pair<int, int>> a, b;
    for (auto x : even) {
        a.push_back({x.second, x.first});
    }
    for (auto x : odd) {
        b.push_back({x.second, x.first});
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int ans = n - a[0].first - b[0].first;
    if (a[0].second == b[0].second){
        int x = a.size();
        int y = b.size();
        if (x > 1 && y > 1){
            ans = n - max(a[0].first + b[1].first , a[1].first + b[0].first);
        }else if (x > 1 && y == 1){
            ans = n - b[0].first - a[1].first;
        }else if (x == 1 && y > 1){
            ans = n - a[0].first - b[1].first;
        }else 
            ans = n/2;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}