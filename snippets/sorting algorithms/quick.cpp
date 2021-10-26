#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
#define ii pair<int, int>

const int mod = 1e9 + 7;
int partition(vector<int>& arr, int start, int end) {
    int partitionIndex = start;
    int pivot = arr[end];
    for (int i = start; i <= end; i++) {
        if (arr[i] <= pivot) {
            swap(arr[partitionIndex], arr[i]);
            partitionIndex++;
        }
    }
    swap(arr[partitionIndex], arr[end]);
    return partitionIndex;
}
void quickSort(vector<int>& arr, int start, int end) {
    if (start >= end)
        return;
    int partitionIndex = partition(arr, start, end);
    quickSort(arr, start, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, end);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr = {4, 5, 2, 2, 7, 6, 3, 8};
    quickSort(arr, 0, 7);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
}