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

int main() {
	int n;
	int count = 1;
	while (cin >> n, n) {
		printf("Case %d:\n", count);
		int s[1000];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int q;
			scanf("%d", &q);
			int temp = 2147483647;
			int result;
			for (int j = 0; j < n; j++) {
				for (int k = j+1; k < n; k++) {
					int sum;
					sum = s[j] + s[k];
					//cout <<"sum = " <<sum <<endl;
					if (temp > abs(sum -q)) {
						result = sum;
						temp = abs(sum - q);
					}
				}
			}

			printf("Closest sum to %d is %d.\n", q, result);
		}
		count++;
	}
	return 0;
}
