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
#include <iterator>
using namespace std;
char arr[120][120], c1, c2;
int m, n;
int br[4] = { 0, 0, -1, 1 };
int bc[4] = { 1, -1, 0, 0 };
int floodfill(int x, int y) {
	if (x >= m || x < 0)
		return 0;
	if (y == -1)
		y = n - 1;
	if (arr[x][y % n] != c1) {
		return 0;
	}
	arr[x][y % n] = c2;
	int ans = 1;
	for (int i = 0; i < 4; i++) {
		ans += floodfill(x + br[i], y + bc[i]);
	}
	return ans;
}
int main() {
	while (scanf("%d %d", &m, &n) != EOF) {

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (i == 0 && j == 0)
					c1 = arr[i][j];
				if (arr[i][j] != c1)
					c2 = arr[i][j];
			}
		int ans = 0;
		int a, b;
		char tmp;
		scanf("%d %d", &a, &b);
		if (c1 != arr[a][b]) {
			tmp = c1;
			c1 = c2;
			c2 = tmp;
		}
		floodfill(a, b);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == c1) {
					ans = max(floodfill(i, j), ans);
				}
			}
		}
		printf("%d\n", ans);

	}
	return 0;
}
