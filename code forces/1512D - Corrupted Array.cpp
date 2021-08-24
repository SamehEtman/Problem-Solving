#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n;
    cin >> n;
    int arr[n + 3];
    ll sum = 0;
    for (int i = 1; i <= n + 2; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 3);

    for (int i = 1; i <= n; i++) {
        sum += arr[i];
    }
    if (sum == arr[n + 1]) {
        for (int i = 1; i <= n; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    } else {
        sum += arr[n + 1];
        int idx = binary_search(arr + 1, arr + n + 2, sum - arr[n + 2]);
        if (idx == 0) {
            cout << -1 << endl;
            return;
        }
        idx = lower_bound(arr + 1, arr + n + 2, sum - arr[n + 2]) - arr;
        for (int i = 1; i <= n + 1; i++) {
            if (i == idx)
                continue;
            cout << arr[i] << " ";
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