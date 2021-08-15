#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x1 = a * d - c * b;
    int x2 = b * c - d * a;

    if (x1 > 0)
    {
        cout << x1 / __gcd(x1, a * d) << "/" << a * d / __gcd(x1, a * b) << endl;
    }
    else
    {
        cout << x2 / __gcd(x2, b * c) << "/" << b * c / __gcd(x2, b * c) << endl;
    }
    return 0;
}
