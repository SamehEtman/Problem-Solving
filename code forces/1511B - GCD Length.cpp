#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    string s1 = "1", s2;
    for (int i = 1; i < a; i++) {
        s1 += '0';
    }
    for (int i = 0; i <= b - c; i++) {
        s2 += '1';
    }
    for (int i = 1; i <= c - 1; i++) {
        s2 += '0';
    }
    cout << s1 << " " << s2 << endl;
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