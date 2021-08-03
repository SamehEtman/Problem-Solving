#define _CRT_SECURE_NO_WARNINGS
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
#define ull unsigned long long

int m;
char a[1010][1010];

void reset() {
	for (int i = 0; i < 1010; i++) {
		for (int j = 0; j < 1010; j++)
			a[i][j] = '0';
	}
}

int call(int x, int y) {
	int min = 9999;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '3') {
				int temp = abs(x - i) + abs(y - j);
				if (temp < min)
					min = temp;
			}
		}
	}

	return min;
}

int main() {
	int i;
	while (cin >> m) {

		reset();

		for (i = 0; i < m; i++) {
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		}

		int max = 0;

		for (i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '1') {
					int min = call(i, j);
					if (min > max)
						max = min;
				}
			}
		}

		cout << max << endl;

	}
	return 0;
}
