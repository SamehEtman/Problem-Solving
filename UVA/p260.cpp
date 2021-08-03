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
char arr[220][220], c1, c2;
int m, n;
int br[] = { -1, -1, 0, 0, 1, 1 };
int bc[] = { -1, 0, -1, 1, 0, 1 };
bool flag = 0;
int floodfill(int x, int y) {
	if (x == n) {
		flag = 1;
		return 0;
	}
	if (y < 0 || y >= n || x < 0 || x >= n)
		return 0;
	if (arr[x][y] != 'b')
		return 0;
	arr[x][y] = '.';
	int ans = 1;
	for (int i = 0; i < 6; i++) {
		ans += floodfill(x + br[i], y + bc[i]);
	}
	return ans;
}
int main() {
	int counter = 1;
	while (scanf("%d", &n) && n) {
		flag = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		for (int i = 0; i < n; i++) {
				floodfill(0, i);
				if (flag)
					break;

		}
		if (flag)
			cout << counter++ << " " << "B\n";
		else
			cout << counter++ << " " << "W\n";

	}
	return 0;
}
