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

int W[3001], C[3001], DP[6002];
int main() {
	int n;
	while (scanf("%d", &n), n) {
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &W[i], &C[i]);
		memset(DP, 0, sizeof DP);
		for (int i = n; i >= 1; i--) {
			for (int j = C[i]; j >= 0; j--) {
				if (DP[j]) {
					DP[j + W[i]] = max(DP[j + W[i]], 1 + DP[j]);
				}
			}
			if (DP[W[i]] == 0)
				DP[W[i]] = 1;
		}
		printf("%d\n", *max_element(DP, DP + 6002));
	}
	return 0;
}
