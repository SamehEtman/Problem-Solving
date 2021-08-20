#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 9;
    {
        int s0 = 0, s1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                s0 += (s[i] != '0');
            else {
                s1 += s[i] == '1';
            }
            if (s0 - s1 > (10 - i) / 2)
                ans = min(ans, i);
            if (s1 - s0 > (9 - i) / 2)
                ans = min(ans, i);
        }
    }
    {
        int s0 = 0, s1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                s0 += (s[i] == '1');
            else {
                s1 += s[i] != '0';
            }
            if (s0 - s1 > (10 - i) / 2)
                ans = min(ans, i);
            if (s1 - s0 > (9 - i) / 2)
                ans = min(ans, i);
        }
    }

    cout << ans + 1 << endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}