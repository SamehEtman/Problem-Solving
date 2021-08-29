#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

void solve() {
    string s, b;
    cin >> s >> b;
    int maxi = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = 1; j < (int)s.size() - i + 1; j++) {
            string temp = s.substr(i, j);
            int step = temp.size();
            for (int k = 0; k < (int)b.size() - step + 1; k++) {
                string temp2 = b.substr(k, step);
                if (temp == temp2) {
                    maxi = max(maxi, step);
                }
            }
        }
    }
    cout << (s.size() - maxi) + b.size() - maxi << endl;
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