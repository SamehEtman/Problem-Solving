#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    printf("PERFECTION OUTPUT\n");
    while (cin >> n && n)
    {
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                //cout << i << " ";
                ans += i;
            }
        }
        if (ans == n)
            cout << setw(5) << n << "  PERFECT\n";
        else if (ans < n)
            cout << setw(5) << n << "  DEFICIENT\n";
        else
            cout << setw(5) << n << "  ABUNDANT\n";
    }
    printf("END OF OUTPUT\n");
    return 0;
}