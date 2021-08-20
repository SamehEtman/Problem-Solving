#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    if (arr[1] == 1) {
        cout << n + 1 << " ";
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n - 1; i++) {
        if (arr[i] == 0 && arr[i + 1] == 1) {
            for (int j = 1; j <= i; j++)
                cout << j << " ";
            cout << n + 1 << " ";
            for (int j = i + 1; j <= n; j++)
                cout << j << " ";
            cout << endl;
            return;
        }
    }
    for (int i = 1; i <= n + 1; i++)
        cout << i << " ";
    cout << endl;
    return;
}
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}