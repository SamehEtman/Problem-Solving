#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        string s(n, 'a');
        for (int i = n - 2; i >= 0; i--)
        {
            if (k <= n - i - 1)
            {
                s[i] = 'b';
                s[n - k] = 'b';
                cout << s << endl;
                break;
            }
            k -= n - i - 1;
        }
    }
}