#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
void build(int l, int r, vector<int>& a, vector<int>& b, int depth) {
    if (l > r) {
        return;
    }
    if (l == r) {
        b[l] = depth;
        return;
    }
    int idx = l;
    for (int i = l; i <= r; i++) {
        if (a[i] > a[idx])
            idx = i;
    }
    b[idx] = depth;
    build(l, idx - 1, a, b, depth + 1);
    build(idx + 1, r, a, b, depth + 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n, 0);
    build(0, n - 1, a, b, 0);
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
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