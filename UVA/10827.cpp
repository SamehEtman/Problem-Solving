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
int arr[350][350];
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				arr[i + n][j] = arr[i][j + n] = arr[i + n][j + n] = arr[i][j];
			}
		}
		for (int i = 0; i < 2 * n; i++)
			for (int j = 0; j < 2 * n; j++) {
				if (i > 0)
					arr[i][j] += arr[i - 1][j];
				if (j > 0)
					arr[i][j] += arr[i][j - 1];
				if (i > 0 && j > 0)
					arr[i][j] -= arr[i - 1][j - 1];
			}

		long long ans = INT32_MIN;

		for (int i = 0; i <  n; i++)
			for (int j = 0; j <  n; j++)
				for (int k = i;k < n+i && k < 2 * n; k++)
					for (int l = j;l < n+j && l < 2 * n; l++) {
						long long temp = arr[k][l];
						if (i > 0)
							temp -= arr[i - 1][l];
						if (j > 0)
							temp -= arr[k][j - 1];
						if (i > 0 && j > 0)
							temp += arr[i - 1][j - 1];
						ans = max (ans , temp);
					}
		printf("%lld\n" , ans);
	}
	return 0;
}
