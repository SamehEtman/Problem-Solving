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
int arr[102][102];
int main() {
	int n , m;
	while (scanf("%d%d" , &n , &m)) {
		if (n == 0 && m == 0) break;
		for (int i = 1 ; i <= n ; i++){
			for (int j = 1 ; j <= m ; j++){
				scanf("%d" , &arr[i][j]);
				arr[i][j] = !arr[i][j];
				if (i > 0) arr[i][j] += arr[i-1][j];
				if (j > 0) arr[i][j] += arr[i][j-1];
				if (i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
			}
		}

	/*	for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}*/
		int sum = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				for (int k = i; k <= n; k++)
					for (int l = j; l <= m; l++) {
						if (arr[k][l] - arr[k][j - 1] - arr[i - 1][l]
								+ arr[i - 1][j - 1]
								== (k - i + 1) * (l - j + 1)) {
							sum =max (sum , (k - i + 1) * (l - j + 1));
						}
					}

		cout << sum << endl;



	}
	return 0;
}
