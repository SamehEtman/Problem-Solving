#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
bool isSquare(int n) {
    int y = sqrt(n);
    return y * y == n;
}
void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0 && isSquare(n / 2)) {
        cout << "YES" << endl;
    } else if (n % 4 == 0 && isSquare(n / 4)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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