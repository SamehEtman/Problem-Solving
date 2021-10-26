#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
#define ii pair<int, int>

const int mod = 1e9 + 7;
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n ; i++) {
        int minJ = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minJ]) {
                minJ = j;
            }
        }
        if (minJ != i) {
            swap(arr[i], arr[minJ]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr = {4, 5, 2, 6, 3, 8};
    selectionSort(arr);
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
}