#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;
        string all;
        int arr[10] = {};
        for (int i = 1; i <= n; i++)
        {
            string newString = to_string(i);
            for (int j = 0; j < newString.size(); j++)
            {
                arr[newString[j] - '0']++;
            }
            all += newString;
        }
        cout << arr[0];
        for (int i = 1; i < 10; i++)
            cout << ' ' << arr[i];
        cout << endl;
    }
    return 0;
}