#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
int binarySearchRec(int arr[], int l, int r, int x)
{

    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
        {
            return binarySearchRec(arr, l, mid - 1, x);
        }
        return binarySearchRec(arr, mid + 1, r, x);
    }
    return -1;
}

int binarySearchIterative(int arr[], int l, int r, int x)
{

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int lowerBound(int arr[], int N, int X)
{
    int mid;

    // Initialise starting index and
    // ending index
    int low = 0;
    int high = N;

    // Till low is less than high
    while (low < high)
    {
        mid = low + (high - low) / 2;

        // If X is less than or equal
        // to arr[mid], then find in
        // left subarray
        if (X <= arr[mid])
        {
            high = mid;
        }

        // If X is greater arr[mid]
        // then find in right subarray
        else
        {
            low = mid + 1;
        }
    }

    // if X is greater than arr[n-1]
    if (low < N && arr[low] < X)
    {
        low++;
    }

    // Return the lower_bound index
    return low;
}

int upperBound(int arr[], int N, int X)
{
    int low = 0;
    int high = N;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (X >= arr[mid])
        {
            low = mid + 1;
        }
        else
            high = mid;
    }

    if (low < N && arr[low] <= X)
        low++;

    return low;
}

int main()
{
    int n = 5;
    int arr[6] = {2, 5, 5, 5, 5, 5}; // first item bigger or equal to X
    cout << upperBound(arr, 5, 5) << endl;
}