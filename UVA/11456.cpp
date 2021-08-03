#define _CRT_SECURE_nO_WARnInGS
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
#define MAX_N 100000

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		int lis[n] , lds[n];
		for (int i = n - 1; i >= 0; i--) {
			lis[i] = 1;
			for (int j = i + 1; j <n; j++) {
				if (arr[i] > arr[j])
					lis[i] = max(lis[i] , lis[j] + 1);
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			lds[i] = 1;
			for (int j = i + 1; j <n; j++) {
				if (arr[i] < arr[j])
					lds[i] = max (lds[i] , lds[j] + 1);
			}
		}

		int ans = 0;
		for (int i = n - 1; i >= 0; i--)
			ans = max(lis[i] + lds[i] - 1, ans);
		printf("%d\n", ans);
	}
	return 0;
}
