#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int zeros, ones;
    cin >> zeros >> ones;
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '?')
            s[i] = s[n - i - 1];
        if (s[i] == '0')
            zeros--;
        if (s[i] == '1')
            ones--;
    }
    for (int i = 0; i <= n / 2; i++) {
        if (s[i] == '?' && i != n - i - 1) {
            if (zeros > 1) {
                s[i] = s[n - i - 1] = '0';
                zeros -= 2;
            } else if (ones > 1) {
                s[i] = s[n - i - 1] = '1';
                ones -= 2;
            }
        } else if (s[i] == '?') {
            if (zeros == 1) {
                s[i] = '0';
                zeros--;
            } else {
                s[i] = '1';
                ones--;
            }
        }
    }

    string temp = s;
    reverse(temp.begin(), temp.end());
    if (s == temp && ones == 0 && zeros == 0)
        cout << s << endl;
    else
        cout << -1 << endl;
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