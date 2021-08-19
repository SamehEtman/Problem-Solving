#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

int main()
{
    int n, t;
    cin >> n >> t;
    int sum[n], arr[n];
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        count += temp;
        arr[i] = temp;
        sum[i] = count;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(sum + i, sum + n, sum[i] - arr[i] + t) - (sum + i);
        ans = max(ans, idx);
    }

    cout << ans << endl;
}