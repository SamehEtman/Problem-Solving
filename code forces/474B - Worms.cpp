#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

int main()
{
    int n;
    cin >> n;
    int arr[n];
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        count += temp;
        arr[i] = count;
    }
    int m;
    cin >> m;
    while (m--)
    {
        int x;
        cin >> x;
        int idx = lower_bound(arr, arr + n, x) - arr;
        cout << idx + 1 << endl;
    }
}