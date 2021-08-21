#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    ll n;
    cin >> n;
    n += 2;
    ll arr[n];
    arr[0] = arr[n - 1] = 0;
    for (ll i = 1; i < n - 1; i++)
        cin >> arr[i];
    ll operations = 0;
    for (ll i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
            operations += arr[i] - max(arr[i - 1], arr[i + 1]);
            arr[i] = max(arr[i - 1], arr[i + 1]);
        }
    }
    ll last = unique(arr, arr + n) - arr;

    ll sum = 0;
    for (ll i = 0; i < last - 1; i++) {
        sum += abs(arr[i + 1] - arr[i]);
    }
    cout << operations + sum << endl;
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