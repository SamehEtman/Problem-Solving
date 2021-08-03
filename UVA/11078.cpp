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
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int maxi = -(1 << 15) +1;
		int n;
		scanf("%d", &n);
		int arr[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		int maxn = arr[0];
		for (int i = 1; i < n; i++) {
			maxi = max (maxi , maxn - arr[i]);
			if (arr[i] > maxn) maxn = arr[i];
		}
		printf("%d\n", maxi);
	}
	return 0;
}
