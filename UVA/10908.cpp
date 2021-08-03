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
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	while (T--) {
		int m, n, q;
		scanf("%d %d %d\n", &m, &n, &q);
		char arr[m][n];
		for (int i = 0; i < m; i++) {
			gets(arr[i]);
		}
		printf("%d %d %d\n", m, n, q);
		while (q--) {
			int x, y;
			scanf("%d %d", &x, &y);
			int ans = 1;
			bool flag = 0;
			for (int i = 0; i < m || i < n; i++) {
				for (int j = x - i; j <= x + i; j++) {
					for (int k = y - i; k <= y + i; k++) {
						if (j < 0 || k < 0 || j >= m || k >= n) {
							flag = 1;
							break;

						}
						if (arr[j][k] != arr[x][y]) {
							flag = 1;
							break;
						}
					}
				}
				if (!flag) {
					ans = max(ans, 2 * i + 1);
				}else{
					break;
				}
			}
			printf("%d\n" , ans);
		}
	}
	return 0;
}
