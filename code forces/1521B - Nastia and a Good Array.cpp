#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;
const int up = 1e7;
bool isPrime[up];
void precalc() {
    memset(isPrime, true, sizeof(isPrime));

    for (ll i = 2; i * i <= up; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= up; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    int minimum = intMax, idx = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < minimum) {
            minimum = arr[i];
            idx = i;
        }
    }
    cout << n - 1 << endl;
    for (int i = 0; i < n; i++) {
        if (idx == i)
            continue;
        cout << idx + 1 << " " << i + 1 << " " << minimum << " "
             << minimum + abs(idx - i) << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // precalc();
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();
}