#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    int arr[n][n] = {};
    int val = 1;
    for (int i = 0; i < n * n; i += 2) {
        int row = i / n;
        int col = i - row * n;
        arr[row][col] = val++;
    }
    for (int i = 1; i < n * n; i += 2) {
        int row = i / n;
        int col = i - row * n;
        arr[row][col] = val++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
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