#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a] += w;
        v[b] -= w;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] > 0)
            ans += v[i];
    }
    cout << ans << endl;
    return 0;
}
