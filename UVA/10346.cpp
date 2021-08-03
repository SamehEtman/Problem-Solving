#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int ans = n, butts = n;
        while (butts >= k)
        {
            n = butts / k;
            butts = butts % k + n;
            ans += n;
        }
        cout << ans << endl;
    }

    return 0;
}