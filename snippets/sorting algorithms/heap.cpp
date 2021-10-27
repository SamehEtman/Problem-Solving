#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
#define ii pair<int, int>

// space comp : best and avg = O(1)
// time comp : worst and avg = O (n log(n)) 

const int mod = 1e9 + 7;
void heapify(vector<int>& arr, int start, int size) {
    int left = 2 * start + 1;
    int right = 2 * start + 2;
    int largest = arr[start];
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != start) {
        swap(arr[largest], arr[start]);
        heapify(arr, largest, size);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i > 0; i--) {
        heapify(arr, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr = {4, 5, 2, 2, 6, 3, 8};
    heapSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
}