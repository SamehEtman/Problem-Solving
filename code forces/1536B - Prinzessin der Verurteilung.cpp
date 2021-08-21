#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= 3; i++) {
        string t(i, 'a');
        while (true) {
            if (s.find(t) == string::npos) {
                cout << t << endl;
                return;
            }
            int idx = i - 1;
            while (idx >= 0 && t[idx] == 'z') {
                t[idx] = 'a';
                idx--;
            }
            if (idx < 0)
                break;
            t[idx]++;
        }
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