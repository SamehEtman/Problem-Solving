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
#include <string.h>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;
int main() {
	int n;
	int counter = 1;
	while (scanf("%d", &n) != EOF) {
		int arr[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		int tot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j && arr[i][j]) {
					for (int k = 0; k < n; k++) {
						if (j != k && arr[j][k]) {
							if (arr[k][i]) {
								if ((i > j && j > k) || (i < j && j < k)) {
									printf("%d %d %d\n", i + 1, j + 1, k + 1);
									tot++;
								}
							}
						}
					}
				}
			}
		}
		printf("total:%d\n\n", tot);
	}

	return 0;
}
