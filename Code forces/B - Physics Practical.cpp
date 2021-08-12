#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = intMax;
    for (int i = 0; i < n; i++)
    {
        int pos = upper_bound(arr.begin(), arr.end(), 2 * arr[i]) - arr.begin();
        ans = min(ans, n - pos + i);
    }
    cout << ans << endl;
    return 0;
}
//  3 3 4 5 7 8
// 6 - 4 + 0