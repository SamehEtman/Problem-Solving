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
int arr[105][105];
int main() {
	int tc;
	scanf("%d", &tc);
	int n, s;
	while (tc--) {

		scanf("%d%d", &n, &s);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = 1;

		for (int i = 0; i < s; i++) {
			int r1, r2, c1, c2;
			scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			for (int j = r1; j <= r2; j++) {
				for (int k = c1; k <= c2; k++) {
					arr[j][k] = 0;
				}
			}
		}


		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i > 0)
					arr[i][j] += arr[i - 1][j];
				if (j > 0)
					arr[i][j] += arr[i][j - 1];
				if (i > 0 && j > 0)
					arr[i][j] -= arr[i - 1][j - 1];
			}
		}


		int sum = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = i; k <= n; k++)
					for (int l = j; l <= n; l++) {
						if (arr[k][l] - arr[k][j - 1] - arr[i - 1][l]
								+ arr[i - 1][j - 1]
								== (k - i + 1) * (l - j + 1)) {
							sum = max(sum, (k - i + 1) * (l - j + 1));
						}
					}

		cout << sum << endl;

	}
	return 0;
}
