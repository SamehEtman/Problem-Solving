#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void solve() {
    ll n, w;
    cin >> n >> w;
    vector<pair<int, int>> arr;
    ll sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp <= w)
            arr.push_back({temp, i + 1});
    }

    sort(arr.begin(), arr.end());

    vector<int> ans1, ans2;
    for (int i = 0; i < arr.size(); i++) {
        if (sum1 + arr[i].first <= w) {
            sum1 += arr[i].first;
            ans1.push_back(arr[i].second);
        }
        if (sum1 >= (w + 1) / 2 && sum1 <= w) {
            cout << ans1.size() << endl;
            for (int i = 0; i < ans1.size(); i++)
                cout << ans1[i] << " ";
            cout << endl;
            return;
        }
    }

    for (int i = (int)arr.size() - 1; i >= 0; i--) {
        if (sum2 + arr[i].first <= w) {
            sum2 += arr[i].first;
            ans2.push_back(arr[i].second);
        }
        if (sum2 >= (w + 1) / 2 && sum2 <= w) {
            cout << ans2.size() << endl;
            for (int i = 0; i < ans2.size(); i++)
                cout << ans2[i] << " ";
            cout << endl;
            return;
        }
    }

    cout << -1 << endl;
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