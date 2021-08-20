#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n, m, k;
    cin >> k >> n >> m;
    int first[n];
    int second[m];
    for (int i = 0; i < n; i++) {
        cin >> first[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> second[i];
    }
    bool flag = 1;
    vector<int> ans;
    int idx1 = 0, idx2 = 0;
    while (flag) {
        flag = 0;
        while (idx1 < n && first[idx1] <= k) {
            flag = 1;
            ans.push_back(first[idx1]);
            if (first[idx1] == 0)
                k++;
            idx1++;
        }
        while (idx2 < m && second[idx2] <= k) {
            flag = 1;
            ans.push_back(second[idx2]);
            if (second[idx2] == 0)
                k++;
            idx2++;
        }
    }
    if (ans.size() != n + m)
        cout << -1 << endl;
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}