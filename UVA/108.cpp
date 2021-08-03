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

int arr[101][101], maxSubRect, subRect;
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				if (i > 0)
					arr[i][j] += arr[i - 1][j];
				if (j > 0)
					arr[i][j] += arr[i][j - 1];
				if (j > 0 && i > 0)
					arr[i][j] -= arr[i - 1][j - 1];
			}
		}
		maxSubRect = -100 * 100 * 127;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				for (int k = i; k < n; k++) {
					for (int l = j; l < n; l++) {
						subRect = arr[k][l];
						if (i > 0)
							subRect -= arr[i - 1][l];
						if (j > 0)
							subRect -= arr[k][j - 1];
						if (j > 0 && i > 0)
							subRect += arr[i - 1][j - 1];
						maxSubRect = max(maxSubRect, subRect);
					}
				}
			}
		printf("%d\n", maxSubRect);
	}
}
