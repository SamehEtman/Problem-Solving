#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

void check(ll x, int& count) {
    map<int, int> mp;
    string s = to_string(x);
    for (int i = 0; i < s.size(); i++)
        mp[s[i]]++;
    if (mp.size() == 3)
        count++;
}

void solve() {
    ll n;
    cin >> n;
    queue<ll> q;
    q.push(3);
    q.push(5);
    q.push(7);
    int count = 0;
    while (true) {
        ll x = q.front() * 10 + 3;
        if (x > n) {
            cout << count << endl;
            return;
        } else {
            check(x, count);
            q.push(x);
        }
        x = q.front() * 10 + 5;
        if (x > n) {
            cout << count << endl;
            return;
        } else {
            check(x, count);
            q.push(x);
        }
        x = q.front() * 10 + 7;
        if (x > n) {
            cout << count << endl;
            return;
        } else {
            check(x, count);
            q.push(x);
        }
        q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}