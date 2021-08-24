#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n * 2);
    for (int i = 0; i < 2 * n; i++)
        cin >> v[i];
    vector<int> sortedV = v, originalV = v;
    sort(sortedV.begin(), sortedV.end());

    int ans1 = 0, ans2 = 0;
    if (v == sortedV) {
        cout << ans1 << endl;
        return;
    }
    while (true) {
        for (int i = 0; i < 2 * n; i += 2) {
            swap(v[i], v[i + 1]);
        }

        ans1++;
        if (v == sortedV) {
            break;
        } else if (v == originalV) {
            ans1 = -1;
            break;
        }

        for (int i = 0; i < n; i++) {
            swap(v[i], v[i + n]);
        }
        ans1++;
        if (v == sortedV) {
            break;
        } else if (v == originalV) {
            ans1 = -1;
            break;
        }
    }
    v = originalV;
    while (true) {
        for (int i = 0; i < n; i++) {
            swap(v[i], v[i + n]);
        }

        ans2++;
        if (v == sortedV) {
            break;
        } else if (v == originalV) {
            ans2 = -1;
            break;
        }

        for (int i = 0; i < 2 * n; i += 2) {
            swap(v[i], v[i + 1]);
        }

        ans2++;
        if (v == sortedV) {
            break;
        } else if (v == originalV) {
            ans2 = -1;
            break;
        }
    }
    if (ans1 > -1 && ans2 > -1) {
        cout << min(ans1, ans2) << endl;
    } else {
        cout << max(ans1, ans2) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}