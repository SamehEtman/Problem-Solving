#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <limits>
#include <set>
#include <iomanip>
using namespace std;
#define ull unsigned long long

int binarySearch(int arr[], int l, int r, int x) {
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was
	// not present
	return -1;
}
int main() {
	int n;
	bool l = 0;
	while (cin >> n) {
		//if (l) cout <<endl;
		int arr[n];
		for (int i = 0; i < n; i++)
			scanf("%d" , &arr[i]);
		sort(arr, arr + n);
		int m;
		scanf("%d\n" , &m);
		vector <pair <int , pair<int,int>>> v;
		for (int i = 0; i < n; i++) {
			int index = binarySearch(arr, 0, n - 1, m - arr[i]);
			if (index != -1 && index != i){
				v.push_back(make_pair(abs(arr[i] - arr[index]) , make_pair(arr[i] , arr[index])));
			}
		}
		sort(v.begin() , v.end());
		printf("Peter should buy books whose prices are %d and %d.\n\n",v[0].second.first , v[0].second.second);
		l=1;
	}
	return 0;
}
