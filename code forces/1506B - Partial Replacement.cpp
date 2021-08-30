#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int res = 1;
    int i = s.find_first_of('*');
    while (true) {
        int j = min(n - 1, i + k);
        for (; i < j && s[j] != '*'; j--) {
        }
        if (i == j) {
            break;
        }
        res++;
        i = j;
    }
    cout << res << "\n";
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