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
    vector<int> toSrot;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool freeze[n];
    for (int i = 0; i < n; i++) {
        cin >> freeze[i];
        if (!freeze[i]) {
            toSrot.push_back(arr[i]);
        }
    }
    sort(toSrot.rbegin(), toSrot.rend());
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (!freeze[i]) {
            arr[i] = toSrot[idx++];
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
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