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
int n, q, m, d;
long long arr[201];
long long dp[210][25][25];
long long solve(int i, int nn, long long mm) {
	if (nn == 0 && mm == 0)
		return dp[i][nn][mm] = 1;
	if (nn == 0)
		return dp[i][nn][mm] = 0;
	if (i == n)
		return dp[i][nn][mm] = 0;
	if (dp[i][nn][mm] != -1)
		return dp[i][nn][mm];
	return dp[i][nn][mm] = solve(i + 1, nn - 1, (mm + arr[i] % d + d) % d)
			+ solve(i + 1, nn, mm);
}

int main() {
	int counter = 1;
	while (scanf("%d%d", &n, &q)) {
		if (n == 0 && q == 0)
			break;
		printf("SET %d:\n", counter++);
		for (int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);

		for (int z = 1; z <= q; z++) {
			memset(dp, -1, sizeof dp);
			scanf("%d%d", &d, &m);
			printf("QUERY %d: %lld\n", z, solve(0, m, 0));
		}

	}

	return 0;

}
