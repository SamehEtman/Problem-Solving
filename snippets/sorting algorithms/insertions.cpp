#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
#define ii pair<int, int>

const int mod = 1e9 + 7;
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int hole = i;
        int value = arr[i];
        while (hole > 0 && arr[hole - 1] > value) {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr = {4, 5, 2, 2, 6, 3, 8};
    insertionSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
}