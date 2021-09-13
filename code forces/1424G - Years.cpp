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
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }
    sort(v.begin(), v.end());
    int count = 0, countOfBestYear = 0, bestYear;
    for (int i = 0; i < v.size(); i++) {
        count += v[i].second;
        if (count > countOfBestYear) {
            countOfBestYear = count;
            bestYear = v[i].first;
        }
    }
    cout << bestYear << " " << countOfBestYear << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();
}