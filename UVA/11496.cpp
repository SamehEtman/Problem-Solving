#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) && n != 0) {
		int arr[n+2];
		int peak = 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 1; i < n - 1; i++) {
			if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
					|| (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
				peak++;
			}
		}
		if ((arr[n - 1] > arr[n - 2] && arr[n - 1] > arr[0])
				|| (arr[n - 1] < arr[n - 2] && arr[n - 1] < arr[0])) {
			peak++;
		}
		if ((arr[0] > arr[n - 1] && arr[0] > arr[1])
				|| (arr[0] < arr[n - 1] && arr[0] < arr[1])) {
			peak++;
		}
		printf("%d\n", peak);
	}

	return 0;
}


//OR 


int main() {
	int n;
	while (scanf("%d", &n) && n != 0) {
		int arr[n + 2];
		int peak = 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		arr[n] = arr[0];
		arr[n + 1] = arr[1];
		for (int i = 1; i < n + 1; i++) {
			if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
					|| (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
				peak++;
			}
		}

		printf("%d\n", peak);
	}

	return 0;
}