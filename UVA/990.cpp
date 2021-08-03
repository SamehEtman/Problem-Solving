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
#define debug(x) cout << '>' << #x << ':' << x << endl;

int dp[31][1002] = { 0 };

int main() {
	int t, w, first = 1;
	;
	while (cin >> t >> w) {
		int n;
		cin >> n;
		if (!first)
			printf("\n");
		else
			first = 0;
		int d1[n + 1], d[n + 1], v[n + 1];
		for (int i = 1; i < n + 1; i++) {
			scanf("%d%d", &d1[i], &v[i]);
			d[i] = (d1[i] * 2 * w) + (w * d1[i]);
		}
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= t; j++) {
				if (d[i] > j) {
					dp[i][j] = dp[i - 1][j];

				} else
					dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - d[i]]);
			}
		}

		int i = 0, ind[31], ans = 0;
		while (n > 0) {
			if (dp[n][t] != dp[n - 1][t]) {
				ind[i++] = n;
				ans += v[n];
				t -= d[n];
			}
			n--;
		}
		printf("%d\n%d\n", ans, i);
		for (int j = i - 1; j >= 0; j--) {
			printf("%d %d\n", d1[ind[j]], v[ind[j]]);
		}
	}
	return 0;
}
