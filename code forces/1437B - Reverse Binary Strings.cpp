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
    int ans1 = 0, ans2 = 0, count1 = 0, count2 = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == s[i + 1] && s[i] == '1') {
            count1++;
        } else {
            ans1 += count1;
            count1 = 0;
        }
        if (s[i] == s[i + 1] && s[i] == '0') {
            count2++;
        } else {
            ans2 += count2;
            count2 = 0;
        }
    }
    ans1 += count1;
    ans2 += count2;
    cout << max(ans1, ans2) << endl;
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