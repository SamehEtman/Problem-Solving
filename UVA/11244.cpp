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
int n, m;
char arr[120][120];
int floodfill(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return 0;
	if (arr[x][y] != '*')
		return 0;
	arr[x][y] = '.';
	int ans = 1;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			ans += floodfill(x + i, y + j);
	return ans;
}
int main() {
	while (scanf("%d %d", &n, &m)) {
		if (!(n && m))
			break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '*') {
					if (floodfill(i, j) == 1)
						ans++;
				}
			}
		}
		printf("%d\n" , ans);
	}
	return 0;
}
