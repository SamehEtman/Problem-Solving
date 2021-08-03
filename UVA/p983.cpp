#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
using namespace std;
int arr[1002][1002];
int main() {
	int n, m , first = 1;
	while (scanf("%d%d", &n, &m) != EOF) {

		if (!first) cout << endl;
		else first = 0;

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i > 0)
					arr[i][j] += arr[i - 1][j];
				if (j > 0)
					arr[i][j] += arr[i][j - 1];
				if (i > 0 && j > 0)
					arr[i][j] -= arr[i - 1][j - 1];
			}
		}

		long long sum = 0;
		int newarr[n - m + 1][n - m + 1] = { 0 };

		for (int i = 0; i < n - m + 1; i++) {
			for (int j = 0; j < n - m + 1; j++) {

				newarr[i][j] = arr[i + m - 1][j + m - 1];
				if (i > 0)
					newarr[i][j] -= arr[i - 1][j + m - 1];
				if (j > 0)
					newarr[i][j] -= arr[i + m - 1][j - 1];
				if (j > 0 && i > 0)
					newarr[i][j] += arr[i - 1][j - 1];

				sum += newarr[i][j];

			}
		}

		for (int i = n - m; i >= 0; i--) {
			for (int j = 0; j < n-m+1; j++)
				printf("%d\n", newarr[i][j]);
		}

		printf("%lld\n", sum);

	}
	return 0;
}
