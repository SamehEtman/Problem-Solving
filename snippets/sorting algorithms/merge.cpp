#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
#define ii pair<int, int>

const int mod = 1e9 + 7;
void merge(vector<int>& left, vector<int>& right, vector<int>& arr) {
    int i, j, k;
    i = j = k = 0;
    int leftLength = left.size(), rightLength = right.size(),
        arrLength = arr.size();

    while (i < leftLength && j < rightLength) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftLength) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < leftLength) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr) {
    int n = arr.size();
    if (n < 2)
        return;
    vector<int> left;
    vector<int> right;
    int mid = n / 2;
    for (int i = 0; i < mid; i++) {
        left.push_back(arr[i]);
    }
    for (int i = mid; i < n; i++) {
        right.push_back(arr[i]);
    }
    mergeSort(left);
    mergeSort(right);

    merge(left, right, arr);
    left.clear();
    right.clear();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr = {4, 5, 2, 2, 7, 6, 3, 8};
    mergeSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
}