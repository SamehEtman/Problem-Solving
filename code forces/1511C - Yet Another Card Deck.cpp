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
    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        bool flag = 1;
        for (int j = 0; j < v.size(); j++) {
            if (arr[i] == v[j].first)
                flag = 0;
        }
        if (flag)
            v.push_back({arr[i], i});
    }
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        sort(v.begin(), v.end(), cmp);
        for (int j = 0; j < v.size(); j++) {
            if (v[j].first == num) {
                // cout << j << "-> ";
                cout << v[j].second << " ";
                for (int k = 0; k < j; k++) {
                    v[k].second++;
                }
                v[j].second = 1;
                break;
            }
        }
        // for (int j = 0; j < v.size(); j++)
        //     cout << v[j].first << "/" << v[j].second << " ";
        // cout << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}