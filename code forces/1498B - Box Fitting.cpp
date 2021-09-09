#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int freeSpace = w, count = 1;
    while (!v.empty()) {
        auto it = upper_bound(v.begin(), v.end(), freeSpace);
        if (it != v.begin()) {
            it--;
            freeSpace -= *it;

            v.erase(it);
        } else {
            freeSpace = w;
            count++;
        }
    }
    cout << count << endl;
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